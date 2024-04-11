#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 405
const int inf=(1<<29);
int f[MAXN][MAXN];
//[l..r] 
int g[MAXN][MAXN];
//[l..r]l
int h[MAXN][MAXN];
//[l..r]r
inline void Max(int &x,int y){if(y>x)x=y;}
int n;int v[MAXN],w[MAXN];
int res[MAXN];
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&v[i]);rep(i,1,n)scanf("%d",&w[i]);
	rep(len,1,n)rep(i,1,n-len+1){
		int j=i+len-1;
		if(i==j){f[i][j]=g[i][j]=h[i][j]=v[1];continue;}
		g[i][j]=h[i][j]=f[i][j]=-inf;
		f[i][j]=f[i+1][j];Max(f[i][j],f[i][j-1]);f[i][j]+=v[1];
		if(w[i]+1==w[j])Max(g[i][j],f[i+1][j-1]+v[2]);
		if(w[i]-1==w[j])Max(h[i][j],f[i+1][j-1]+v[2]);
		rep(k,i+1,j-1)if(w[i]<w[k]&&w[k]<w[j]){		// 
			int A=w[k]-w[i];int B=w[j]-w[k];
			//k 
			if(A>k-i||B>j-k)continue;
			Max(g[i][j],g[i][k]+g[k][j]-v[A+1]-v[B+1]+v[A+B+1]);
			//V 
		}
		rep(k,i+1,j-1)if(w[i]>w[k]&&w[k]>w[j]){		//
			int A=w[i]-w[k];int B=w[k]-w[j];
			if(A>k-i||B>j-k)continue;
			Max(h[i][j],h[i][k]+h[k][j]-v[A+1]-v[B+1]+v[A+B+1]);
		}
		rep(k,i+1,j-1)if(w[i]<w[k]&&w[k]>w[j]){
			//k
			int A=w[k]-w[i];int B=w[k]-w[j];
			if(A>k-i||B>j-k)continue;
			Max(f[i][j],g[i][k]+h[k][j]-v[A+1]-v[B+1]+v[A+B+1]);
		}
		rep(k,i,j-1)Max(f[i][j],f[i][k]+f[k+1][j]);
		Max(f[i][j],g[i][j]);Max(f[i][j],h[i][j]);
	}
	rep(i,1,n)res[i]=-inf;
	rep(i,1,n){
		res[i]=res[i-1];
		rep(j,1,i)Max(res[i],res[j-1]+f[j][i]);
	}
	printf("%d\n",res[n]);
	return 0;
}