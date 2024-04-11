// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10;

vector<ll>v[maxn];
vector<ll>path;
vector<ll>ans[maxn];

bool mark[maxn];
void dfs(ll u){
	path.PB(u);
	mark[u]=1;
	REP(i,sz(v[u])){
		ll y=v[u][i];
		if(!mark[y]){
			dfs(y);
			path.PB(u);
		}
	}
}

int main(){
	ll n,m,k;scanf("%d%d%d",&n,&m,&k);
	REP(i,m){
		ll a,b;scanf("%d%d",&a,&b);
		v[a].PB(b);
		v[b].PB(a);
	}
	dfs(1);
	ll lim=((2*n)/k)+((2*n)%k!=0);
	ll a=sz(path)/k,b=((sz(path)/k)+(sz(path)%k!=0));
	ll pb=sz(path)-a*k;ll pa=k-pb;
	ll h=0;

	REP(i,pa)
		REP(j,a)
			ans[i].PB(path[h++]);
	REP(i,pb)
		REP(j,b)
			ans[i+pa].PB(path[h++]);
	
	REP(i,k){
		if(sz(ans[i])==0)
			ans[i].PB(1);
		printf("%d ",sz(ans[i]));
		REP(j,sz(ans[i]))
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}