#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int P=1000000007;
const int N=110000;
vector<int>p[N];int n;
int f[N][2];
int g[2];
void dfs(int x){
	rep(i,0,p[x].size()-1)dfs(p[x][i]);
	sort(p[x].begin(),p[x].end());
	g[0]=1;g[1]=0;int t1,t0;
	int ret=1;
	rep(i,0,p[x].size()-1){
		int v=p[x][i];
		t1=(g[0]*1ll*f[v][1]+g[1]*1ll*f[v][0])%P;
		t0=(g[0]*1ll*f[v][0]+g[1]*1ll*f[v][1])%P;
		g[0]=t0;g[1]=t1;
		ret=ret*1ll*f[v][0]%P;
	}
	
	f[x][1]=g[0]*2ll%P;
	f[x][0]=g[1]*2ll%P;
	
	g[0]=1;g[1]=0;
	rep(i,0,p[x].size()-1){
		int v=p[x][i];
		t1=(g[1]+1ll*g[0]*f[v][1])%P;
		t0=(g[0]+1ll*g[1]*f[v][1])%P;
		g[0]=t0;g[1]=t1;
	}
	
	f[x][0]=(f[x][0]-g[1])%P;
	f[x][1]=(f[x][1]-ret)%P;
	
	f[x][0]=(f[x][0]+1)%P;
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int x;scanf("%d",&x);
		p[x].pb(i);
	}
	dfs(1);
	int ans=(f[1][0]+f[1][1])%P;
	ans=(ans-1)%P;
	printf("%d\n",(ans+P)%P);
	return 0;
}