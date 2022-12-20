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

using namespace std;
typedef int ll;////
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=3e5+10;

ll n,k,d;
vector<pll>v[maxn];
ll mark[maxn];
ll dis[maxn];
vector<ll>ans;
queue<ll>q;
bool used[maxn];

int main(){
	cin>>n>>k>>d;
	ll h=1;
	REP(i,k){
		ll x;cin>>x;
		if(!mark[x]){
			mark[x]=h++;
			q.push(x);
		}
	}
	REP(i,n-1){
		ll a,b;cin>>a>>b;
		v[a].PB(MP(b,i+1));
		v[b].PB(MP(a,i+1));
	}
	while(sz(q)){
		ll t=q.front();
		q.pop();
		REP(i,sz(v[t])){
			ll y=v[t][i].F;
			if(mark[y]!=0&&mark[y]!=mark[t]){
				if(!used[v[t][i].S]){
					used[v[t][i].S]=1;
					ans.PB(v[t][i].S);
				}
			}
			if(mark[y]==0&&dis[t]!=d){
				mark[y]=mark[t];
				dis[y]=dis[t]+1;
				q.push(y);
			}
		}
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans)){
		cout<<ans[i]<<" ";
	}
}