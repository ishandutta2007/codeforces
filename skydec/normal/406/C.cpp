#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
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
const int MAXN=210000;
vector<int>p[MAXN],id[MAXN];int n,m;bool use[MAXN];
int dfs(int x){
	vector<int>tmp;vector<int>need;
	rep(i,0,S(p[x])-1)if(!use[id[x][i]]){use[id[x][i]]=1;need.pb(p[x][i]);}
	rep(i,0,S(need)-1){
		int w=dfs(need[i]);
		if(w)printf("%d %d %d\n",x,need[i],w);
		else tmp.pb(need[i]);
	}
	while(S(tmp)>1){
		int u=tmp[S(tmp)-1];
		int v=tmp[S(tmp)-2];
		tmp.pop_back();tmp.pop_back();
		printf("%d %d %d\n",u,x,v);
	}
	if(S(tmp))return tmp[0];
	else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	if(m&1){
		printf("No solution\n");
		return 0;
	}
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);id[x].pb(i);id[y].pb(i);
	}
	dfs(1);
	return 0;
}