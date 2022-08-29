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
const int MAXN=805;
int f[MAXN],g[MAXN],o[MAXN];
int n,m;
vector<int>p[110000];
int q[110000];
int main(){
	scanf("%d%d",&n,&m);int res=0;
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		if(x<=n-800)res+=3;
		else p[y].pb(n-x+1);
	}
	rep(i,1,n)sort(p[i].begin(),p[i].end());
	memset(o,63,sizeof o);
	o[0]=0;
	rep(i,1,n){
		int up=min(n-i+1,800);
		int N=p[i].size();
		rep(j,1,N)q[j]=p[i][j-1];
		int v=0;
		f[0]=N*3+o[0];
		f[0]=min(f[0],N*3+o[1]);
		rep(j,1,up){
			while(v<N&&q[v+1]<=j)v++;
			f[j]=g[j]+(j*(j+1)/2)+2+(N-v)*3;
			f[j]=min(f[j],o[j+1]+(N-v)*3);
		}
		rep(j,0,up)o[j]=f[j],f[j]=o[804];
		g[0]=o[0];rep(j,1,up)g[j]=min(g[j-1],o[j]);
	}
	printf("%d\n",g[1]+res);
	return 0;
}