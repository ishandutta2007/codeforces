#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5;
pr dp[N];
vector<int>g[N];
int n,k;
void dfs(int x,int fa){
	if(g[x].size()==1){dp[x]=mp(1,0);return;}
	dp[x]=mp(0,0);
	vector<int>s;s.clear();
	for(auto v:g[x])if(v!=fa){
		dfs(v,x);
		dp[x].fr+=dp[v].fr;
		s.pb(dp[v].sc+1);
	}
	sort(s.begin(),s.end());
	int i=0,mx=s.size();
	for(;i<mx;++i)if(i+1>=mx||s[i]+s[i+1]>k)break;
	dp[x].fr-=i;
	dp[x].sc=s[i];
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y),g[y].pb(x);
	}
	int rt=1;
	while(g[rt].size()==1)++rt;
	dfs(rt,0);
	printf("%d\n",dp[rt].fr);
	return 0;
}