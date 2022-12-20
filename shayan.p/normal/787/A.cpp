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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=5e4+10;

bool mark[maxn];

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll g=gcd(a,c);
	ll lcm=(a*c)/g;
	ll M=max(b,d)+lcm;
	for(ll i=b;i<=M;i+=a){
		mark[i]=1;
	}
	for(ll i=d;i<=M;i+=c){
		if(mark[i]){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}