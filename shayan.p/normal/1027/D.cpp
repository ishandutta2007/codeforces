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
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll c[maxn],a[maxn];
int mark[maxn];
vector<ll>v[maxn];

void dfs(ll u){
    mark[u]=2;
    for(ll x:v[u]){
	if(mark[x]!=2)
	    dfs(x);
    }
}

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>c[i];
    }
    FOR(i,1,n){
	cin>>a[i];
	v[a[i]].PB(i);
    }
    ll ans=0;
    FOR(i,1,n){
	ll tmp=i;
	if(mark[tmp]==2)continue;
	while(mark[tmp]==0){
	    mark[tmp]=1;
	    tmp=a[tmp];
	}
	ll x=c[tmp],y=tmp;
	tmp=a[tmp];
	while(tmp!=y){
	    x=min(c[tmp],x);
	    tmp=a[tmp];
	}
	ans+=x;
	dfs(y);
    }
    cout<<ans;
}