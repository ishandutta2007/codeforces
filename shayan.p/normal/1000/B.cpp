// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
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

ll delta,neg;
ll a[maxn];

int main(){
    ll n,m;cin>>n>>m;
    FOR(i,1,n){
	cin>>a[i];
    }
    a[n+1]=m;
    FORD(i,n,0){
	if(i%2){
	    if(a[i]+1 != a[i+1])
	       delta=max(delta,-neg+a[i+1]-a[i]-1);
	    neg-=a[i+1]-a[i];
	    if(a[i-1]+1 != a[i])
		delta=max(delta,-neg-1);
	}
	else{
	    neg+=a[i+1]-a[i];
	}
    }
    ll ans=((neg+m)/2)+delta;
    cout<<ans;
}