// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn=1e6+10;

map<int,int>mp[maxn];// depth size
pii ans[maxn];// size depth
vector<int>v[maxn];
int h[maxn];

void dfs(int u,int par=-1){
    ans[u]=MP(1,h[u]);
    mp[u][h[u]]++;
    for(int y:v[u]){
	if(y!=par){
	    h[y]=h[u]+1;
	    dfs(y,u);
	    if(ans[u].F<ans[y].F)
		ans[u]=ans[y];
	    if(ans[u].F==ans[y].F && ans[u].S>ans[y].S)
		ans[u]=ans[y];
	    if(sz(mp[y])>sz(mp[u]))
		swap(mp[u],mp[y]);
	    for(pii p:mp[y]){
		mp[u][p.F]+=p.S;
		int x=mp[u][p.F];
		if(x>ans[u].F)
		    ans[u]=MP(x,p.F);
		if(x==ans[u].F && p.F<ans[u].S)
		    ans[u]=MP(x,p.F);
	    }
	    mp[y].clear();
	}
    }
}

int main(){
    int n;scanf("%d",&n);
    REP(i,(n-1)){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    FOR(i,1,n){
	printf("%d\n",ans[i].S-h[i]);
    }
}