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
const ll Big=1e9+1;

ll a[maxn],tw[maxn],hmd[maxn];
ll l[maxn],val[maxn];// be soorat (]
ll TW[35];
ll spl[maxn][23],spv[maxn][23];

inline ll calc(ll l,ll r){// (]
    return (hmd[l+1]-tw[r-l]*hmd[r+1])%mod;
}

int main(){
    
    TW[0]=tw[0]=1;
    FOR(i,1,34){
	TW[i]=2*TW[i-1];
    }
    FOR(i,1,maxn-1){
	tw[i]=(2*tw[i-1])%mod;
    }
    
    ll n,q;cin>>n>>q;
    FOR(i,1,n){
	cin>>a[i];
    }
    FORD(i,n,1){
	hmd[i]=(2*hmd[i+1]+a[i])%mod;
    }
    FOR(i,1,n){
	val[i]=a[i];
	l[i]=i-1;
	while(l[i]>0 && val[i]>=0 && val[i]<Big){
	    if(val[i]==0){
		val[i]=val[l[i]];
		l[i]=l[l[i]];
	    }
	    else{
		ll d=l[i]-l[l[i]];
		if(d>31){
		    val[i]=Big;
		    l[i]=0;
		}
		else{
		    val[i]=TW[d]*val[i]+val[l[i]];
		    l[i]=l[l[i]];
		}
	    }
	}
	if(val[i]>=Big)
	    l[i]=0,val[i]=Big;
	spl[i][0]=l[i];
	spv[i][0]=calc(l[i],i);
    }
    
    FOR(j,1,20){
	FOR(i,1,n){
	    spl[i][j]=spl[spl[i][j-1]][j-1];
	    spv[i][j]=(spv[i][j-1]+spv[spl[i][j-1]][j-1])%mod;
	}
    }

    while(q--){
	ll f,s,ans=0;cin>>f>>s;
	FORD(i,20,0){
	    if(spl[s][i]>(f-1)){
		ans=(ans+2*spv[s][i])%mod;
		s=spl[s][i];
	    }
	}
	ans=(ans+calc(f-1,s))%mod;
	cout<<(ans+mod)%mod<<endl;
    }
}