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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

map<ll,ll>mp;
ll a[maxn],sp[maxn][23];

ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}

int main(){
    ll n;scanf("%lld",&n);
    FOR(i,1,n){
	scanf("%lld",&a[i]);
	sp[i][0]=a[i];
    }
    FOR(j,1,20){
	FOR(i,1,n){
	    sp[i][j]=gcd(sp[i][j-1],sp[min(n,ll(i+(1<<(j-1))))][j-1]);
	}
    }
    FOR(i,1,n){
	ll x=a[i],pos=i;
	while(pos<=n){
	    ll was=pos;
	    FORD(j,20,0){
		if(gcd(x,sp[pos][j])==x){
		    pos=min(n+1,pos+(1<<j));
		}
	    }
	    mp[x]+=pos-was;
	    if(pos>n)break;
	    x=gcd(x,a[pos]);
	}
    }
    ll q;scanf("%lld",&q);
    while(q--){
	ll x;scanf("%lld",&x);
	printf("%lld\n",mp[x]);
    }
}