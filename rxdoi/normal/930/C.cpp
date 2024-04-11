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

const int oo=(1<<30)-1;
const int N=1e5+19;

int A[N],C[N],F[N],G[N];
int n,m,x,y,ans;

void Add(int x,int v){
	for (x++;x<N;x+=x&-x) C[x]=max(C[x],v);
}
int Qry(int x){
	int mx=0;
	for (x++;x;x-=x&-x) mx=max(mx,C[x]);
	return mx;
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		A[x]++,A[y+1]--;
	}
	For(i,1,m+1) A[i]+=A[i-1];
	For(i,1,m+1){
		F[i]=Qry(A[i])+1;
		Add(A[i],F[i]);
	}
	memset(C,0,sizeof(C));
	for (int i=m;i;i--){
		G[i]=Qry(A[i])+1;
		Add(A[i],G[i]);
	}
	For(i,1,m+1) ans=max(ans,F[i]+G[i]-1);
	printf("%d\n",ans);
}