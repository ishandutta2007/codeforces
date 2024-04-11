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
const ll maxn=3e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

pll p[maxn];
set<ll>em;
ll ans[maxn],ANS;

int main(){
    ll n,k;cin>>n>>k;
    REP(i,n){
	cin>>p[i].F;
	p[i].S=i;
	em.insert(i+k);
    }
    sort(p,p+n,greater<pll>());
    REP(i,n){
	set<ll>::iterator it=em.lower_bound(p[i].S);
	ans[p[i].S]=*it;
	ANS+=p[i].F*((*it)-p[i].S);
	em.erase(it);
    }
    cout<<ANS<<endl;
    REP(i,n){
	cout<<ans[i]+1<<" ";
    }
}