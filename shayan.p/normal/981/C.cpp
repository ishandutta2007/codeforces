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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
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

ll deg[maxn];

int main(){
	ll n;cin>>n;
	REP(i,(n-1)){
		ll a,b;cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	ll cnt=0;
	FOR(i,1,n){
		cnt+=(deg[i]>2);
	}
	if(cnt>1){
		cout<<"No";
	}
	else{
		cout<<"Yes\n";
		vector<ll>vec;
		ll A=-1;
		FOR(i,1,n){
			if(deg[i]==1)
				vec.PB(i);
			if(deg[i]>2)
				A=i;
		}
		if(A==-1){
			cout<<1<<endl<<vec[0]<<" "<<vec[1];
		}
		else{
			cout<<sz(vec)<<endl;
			REP(i,sz(vec))
				cout<<vec[i]<<" "<<A<<endl;
		}
	}
}