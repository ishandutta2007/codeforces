#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=6e5+19;

ll A[N],B[N],T[N],sum[N];
int n,L;
ll x;

void work(int l,int r){
	sum[l]++;
	sum[r+1]--;
}
void gao(int l,int r,int i){
	if (r-l+1>=n){
		work(1,n);
		return;
	}
	l=(l-i+n)%n;
	r=(r-i+n)%n;
	if (l<=r){
		work(l+1,r+1);
	} else{
		work(l+1,n);
		work(1,r+1);
	}
}
bool check(int w){
	memset(sum,0,sizeof(sum));
	int l=0,r=1;
//	printf("w=%d\n",w);
	For(i,1,n+1){
		while (A[l]<B[i]-w) l++;
		while (A[r+1]<=B[i]+w) r++;
		if (l>r) return 0;
		gao(l,r,i);
		//printf("[%d,%d]\n",l,r);
	}
	For(i,1,n+1){
		sum[i]+=sum[i-1];
		if (sum[i]==n) return 1;
	}
	return 0;
}

int main(){
	n=IN(),L=IN();
	For(i,1,n+1) T[i]=IN();
	sort(T+1,T+n+1);
	For(i,1,n+1){
		x=T[i];
		A[i]=x-L;
		A[i+n]=x;
		A[i+2*n]=x+L;
	}
	A[0]=-(1ll<<60);
	A[3*n+1]=1ll<<60;
	For(i,1,n+1) B[i]=IN();
	sort(B+1,B+n+1);
	int l=0,r=L;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;else l=mid+1;
	}
	printf("%d\n",r+1);
}