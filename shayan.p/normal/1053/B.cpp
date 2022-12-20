// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn];
int cnt[maxn][2];

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,n){
	ll x;scanf("%lld",&x);
	a[i]=__builtin_popcountll(x);
    }
    FORD(i,n,1){
	if(a[i]&1){
	    cnt[i][0]=cnt[i+1][1];
	    cnt[i][1]=1+cnt[i+1][0];
	}
	else{
	    cnt[i][0]=1+cnt[i+1][0];
	    cnt[i][1]=cnt[i+1][1];
	}
    }
    
    ll ans=0;
    FOR(i,1,n){
	int mx=0,sm=0;
	FOR(j,i,min(i+62,n)){
	    mx=max(mx,a[j]);
	    sm+=a[j];
	    if((sm-mx)<mx || sm&1)
		ans++;
	}
	int nw=i+63;
	if(nw<=n){
	    ans+=cnt[nw][1-(sm&1)];
	}
    }

    ll N=n;
    
    ans=N+((N*(N-1))/2)-ans;

    printf("%lld\n",ans);
}