// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

vector<ll>q[maxn];
ll h[maxn];
bool vis[maxn];
vector<ll>v[maxn];
vector<ll>gd[maxn];

int main(){
    ll n,m,k,s;cin>>n>>m>>k>>s;
    FOR(i,1,n){
	ll x;cin>>x;
	q[x].PB(i);
    }
    REP(i,m){
	ll a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    FOR(i,1,k){
	memset(vis,0,sizeof vis);
	memset(h,0,sizeof h);
	queue<ll>Q=(queue<ll>());
	REP(j,sz(q[i])){
	    vis[q[i][j]]=1;
	    Q.push(q[i][j]);
	}
	while(sz(Q)){
	    ll t=Q.front();
	    Q.pop();
	    gd[t].PB(h[t]);
	    REP(j,sz(v[t])){
		ll y=v[t][j];
		if(!vis[y]){
		    vis[y]=1;
		    h[y]=h[t]+1;
		    Q.push(y);
		}
	    }
	}
    }
    FOR(i,1,n){
	sort(gd[i].begin(),gd[i].end());
	ll ans=0;
	REP(j,s){
	    ans+=gd[i][j];
	}
	cout<<ans<<" ";
    }
}