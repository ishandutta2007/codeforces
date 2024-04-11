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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=1010;

#pragma GCC Optimize("Ofast")

ll ans[maxn];
ll l[maxn],r[maxn];

int main(){
	ll t;cin>>t;
	REP(i,t){
		ll n;cin>>n;
		ll tm=1;
		queue<ll>q;
		memset(ans,0,sizeof ans);
		REP(j,n){
			cin>>l[j]>>r[j];
			while(sz(q)&&tm<l[j]){
				ll tp=q.front();
				q.pop();
				if(r[tp]>=tm){
					ans[tp]=tm;
					tm++;
				}
			}
			if(tm<l[j])
				tm=l[j];
			q.push(j);
		}
		while(sz(q)){
			ll tp=q.front();
			q.pop();
			if(r[tp]>=tm){
				ans[tp]=tm;
				tm++;
			}
		}
		REP(j,n)
			cout<<ans[j]<<" ";
		cout<<endl;
	}
}