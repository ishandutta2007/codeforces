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
const ll maxn=2e6+100;

#pragma GCC Optimize("Ofast")

vector<ll>v[maxn];
string s[maxn];

int main(){
	ll n,sm=0;cin>>n;
	REP(i,n){
		cin>>s[i];
		ll t;cin>>t;
		sm+=t;
		while(t--){
			ll ind;cin>>ind;
			v[--ind].PB(i);
		}
	}
	ll vis=0,lst=0,id=-1,now=0;
	while(vis<sm||id!=-1){
		if(vis!=sm){
			REP(i,sz(v[now])){
				if(id==-1){
					id=v[now][i];
					lst=0;
				}
				if((sz(s[id])-lst)<sz(s[v[now][i]])){
					id=v[now][i];
					lst=0;
				}
			}
		}
		if(id==-1)
			cout<<'a';
		else
			cout<<s[id][lst++];
		vis+=sz(v[now++]);
		if(id!=-1&&sz(s[id])==lst)
			id=-1;
	}
}