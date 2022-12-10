#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

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
typedef vector<int> Vi;
typedef pair<int,int> pii;

const int len=200000;
inline char nc(){
	static char buf[len],*b=buf+len;
	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
	return *b++;
}
int IN(){
	int c,f,x;
	while (!isdigit(c=nc())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=nc())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=4000+19;
const int K=800+19;
const int oo=(1<<30)-1;
const int inf=2147483647;

int f[N],g[N];
int G[N][N];
int A[N][N];
int n,k,res,l,r;

struct node{
	int p,x,y;
} Q[N];

void check(int d){
	int l=1,r=1;
	Q[1]=(node){0,1,n};
	For(i,0,N) f[i]=inf,g[i]=-1;
	f[0]=0,g[0]=0;
	For(i,1,n+1){
		int j=Q[l].p;
		f[i]=f[j]+G[i][j+1]+d;
		g[i]=g[j]+1;
		if (Q[l].x==Q[l].y) l++;else Q[l].x++;
		while (r>=l){
			int a=Q[r].x,j=Q[r].p;
			if (mp(0ll+f[i]+G[a][i+1]+d,g[i]+1)<mp(0ll+f[j]+G[a][j+1]+d,g[j]+1)) r--;else break;
		}
		if (r<l){
			Q[++r]=(node){i,i+1,n};
		} else{
			int a=Q[r].x,b=Q[r].y,j=Q[r].p;
			while (a<=b){
				int c=(a+b)/2;
				if (mp(0ll+f[i]+G[c][i+1]+d,g[i]+1)<mp(0ll+f[j]+G[c][j+1]+d,g[j]+1)) b=c-1;else a=c+1;
			}
			if (b+1<=n){
				Q[r].y=b;
				Q[++r]=(node){i,b+1,n};
			}
		}
	}
}

int main(){
	n=IN();k=IN();
	For(i,1,n+1){
		For(j,1,n+1) A[i][j]=IN();
	}
	For(i,1,n+1){
		For(j,1,n+1) A[i][j]+=A[i][j-1];
	}
	For(i,1,n+1){
		For(j,i,n+1){
			G[j][i]=G[j-1][i]+A[j][j]-A[j][i-1];
		}
	}
	l=0,r=oo;
	while (l<=r){
		int mid=(l+r)/2;
		check(mid);
		if (g[n]<=k){
			res=f[n]-k*mid;
			r=mid-1;
		} else{
			l=mid+1;
		}
	}
	printf("%d\n",res);
}