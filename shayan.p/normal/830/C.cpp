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
const ll maxn=110;
const ll mod=1e9+7;
const ll SQ=2e5;

ll a[maxn],n,k;
vector<ll>tdo;

inline ll saghf(ll a,ll b){
    return (a/b)+((a%b)!=0);
}

int main(){
    cin>>n>>k;
    FOR(i,1,SQ)
	tdo.PB(i);
    REP(i,n){
	cin>>a[i];
	k+=a[i];
	ll j=1;
	while(saghf(a[i],j)>SQ){
	    tdo.PB(saghf(a[i],j));
	    j++;
	}
    }
    tdo.PB(inf);
    sort(tdo.begin(),tdo.end());
    
    ll ans=1;
    REP(i,sz(tdo)-1){
	ll sm=0;
	REP(j,n)
	    sm+=saghf(a[j],tdo[i]);
	ll d=k/sm;
	if(d>=tdo[i])
	    ans=max(ans,min(tdo[i+1]-1,d));
    }
    cout<<ans;
}