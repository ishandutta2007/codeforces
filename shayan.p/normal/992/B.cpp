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
#define REP(i,n)  for(int i=0;i<n;i++)
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
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    ll l,r,x,y;cin>>l>>r>>x>>y;
    l=(l/x)+(l%x!=0);
    r=(r/x);
    if(y%x!=0){
	cout<<0;
	return 0;
    }
    y=y/x;
    ll ans=0;
    FOR(i,1,sqrt(y)){
	if(y%i==0){
	    ll q=i,w=y/i;
	    if(l<=q&&q<=r&&l<=w&&w<=r&&gcd(q,w)==1)
		ans+=(q==w?1:2);
	}
    }
    cout<<ans;
}