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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e6+10;

bool hole[maxn];
bool cup[maxn];

int main(){
	ll n,m,k;cin>>n>>m>>k;
	REP(i,m){
		ll x;
		scanf("%d",&x);
		hole[x]=1;
	}
	ll now=1;
	cup[1]=1;
	if(hole[1]){
		cup[1]=0;
	}
	REP(i,k){
		ll a,b;
		scanf("%d%d",&a,&b);
		if(cup[a]==1&&hole[b]){
			now=b;
			cup[a]=0;
		}
		if(cup[b]&&hole[a]){
			now=a;
			cup[b]=0;
		}
		if(cup[a]){
			cup[a]=0;
			cup[b]=1;
			now=b;
		}
		else if(cup[b]){
			cup[b]=0;
			cup[a]=1;
			now=a;
		}
	}
	cout<<now;
}