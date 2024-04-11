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
const int N=210000;
vector<int>p[N];
int v[N];bool in[N];
vector<int>ans;
int n,m;
void dfs(int x){
	v[x]^=1;ans.pb(x);in[x]=1;
	rep(i,0,p[x].size()-1){
		int y=p[x][i];
		if(in[y])continue;
		dfs(y);
		ans.pb(x);v[x]^=1;
		if(v[y]){
			ans.pb(y);
			ans.pb(x);
			v[y]^=1;
			v[x]^=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		p[a].pb(b);p[b].pb(a);
	}
	rep(i,1,n)scanf("%d",&v[i]);
	rep(i,1,n)if(v[i]){
		dfs(i);
		if(v[i]){ans.pop_back();v[i]=0;}
		break;
	}
	int sum=0;
	rep(i,1,n)sum+=v[i];
	if(sum)printf("-1");
	else{
		printf("%d\n",ans.size());
		rep(i,0,ans.size()-1)printf("%d ",ans[i]);
	}
	return 0;
}