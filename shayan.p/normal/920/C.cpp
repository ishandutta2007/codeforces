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
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll a[maxn],b[maxn];

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
		b[i]=a[i];
	}
	string s;cin>>s;
	
	ll beg=0;
	vector<pll>seg;
	REP(i,sz(s)){
		if(s[i]=='0'){
			seg.PB(MP(beg,i));
			beg=i+1;
		}
	}
	seg.PB(MP(beg,n-1));
	sort(b,b+n);
	REP(i,sz(seg)){
		sort(a+seg[i].F,a+seg[i].S+1);
	}
	REP(i,n){
		if(a[i]!=b[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}