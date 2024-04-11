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
const ll maxn=2e5+10;

int main(){
	ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	x1=abs(x2-x1);
	y1=abs(y2-y1);
	ll x,y;cin>>x>>y;
	if(x1%x!=0||y1%y!=0){
		cout<<"NO";
		return 0;
	}
	x1/=x;
	y1/=y;
	if(((x1%2)+(y1%2))%2){
		cout<<"NO";
		return 0;
	}
	else{
		cout<<"YES";
		return 0;
	}
}