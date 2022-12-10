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

const int N=100000+19;

int n,d,b,l,r;
ll A[N],B[N];

bool check(int w){
	memcpy(B,A,sizeof(A));
	int l=w+1,r=n-w,x=1,y=n;
	for (int i=l;i<=(n+1)/2;i++){
		while (B[i]<b){
			while (x<=n&&(abs(i-x)>1ll*i*d||!B[x]||x==i)) x++;
			if (abs(i-x)>1ll*i*d) return 0;
			ll tmp=min(b-B[i],B[x]);
			B[i]+=tmp;
			B[x]-=tmp;
		}
		if (B[i]<b) return 0;
		B[i]-=b;
	}
	for (int i=r;i>(n+1)/2;i--){
		while (B[i]<b){
			while (y>=1&&(abs(i-y)>1ll*(n-i+1)*d||!B[y]||y==i)) y--;
			if (abs(i-y)>1ll*(n-i+1)*d) return 0;
			ll tmp=min(b-B[i],B[y]);
			B[i]+=tmp;
			B[y]-=tmp;
		}
		if (B[i]<b) return 0;
		B[i]-=b;
	}
	return 1;
}
bool check2(int w){
	memcpy(B,A,sizeof(A));
	int l=w+1,r=n-w,x=1,y=n;
	for (int i=r;i>(n+1)/2;i--){
		while (B[i]<b){
			while (y>=1&&(abs(i-y)>1ll*(n-i+1)*d||!B[y]||y==i)) y--;
			if (abs(i-y)>1ll*(n-i+1)*d) return 0;
			ll tmp=min(b-B[i],B[y]);
			B[i]+=tmp;
			B[y]-=tmp;
		}
		if (B[i]<b) return 0;
		B[i]-=b;
	}
	for (int i=l;i<=(n+1)/2;i++){
		while (B[i]<b){
			while (x<=n&&(abs(i-x)>1ll*i*d||!B[x]||x==i)) x++;
			if (abs(i-x)>1ll*i*d) return 0;
			ll tmp=min(b-B[i],B[x]);
			B[i]+=tmp;
			B[x]-=tmp;
		}
		if (B[i]<b) return 0;
		B[i]-=b;
	}
	return 1;
}

int main(){
	n=IN(),d=IN(),b=IN();
	For(i,1,n+1) A[i]=IN();
	l=0,r=(n-1)/2;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)||check2(mid)){
			r=mid-1;
		} else{
			l=mid+1;
		}
	}
	printf("%d\n",r+1);
}