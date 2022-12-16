// Jump, and you will find out how to unfold your wings as you fall.

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],p;
vector<int>vec,cnt,val;

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %p)
	if(b&1)
	    ans=1ll*ans*a %p;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m>>p;
    for(int i=1;i*i<=p-1;i++){
	if((p-1)%i==0)
	    vec.PB(i);
    }
    for(int i=sz(vec)-1;i>=0;i--){
	if(vec[i]*vec[i]==p-1) continue;
	vec.PB((p-1)/vec[i]);
    }
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int g=p-1;
    for(int i=0;i<m;i++){
	int x;cin>>x;
	g=__gcd(g,x);
    }
    for(int i=0;i<n;i++){
	a[i]=Pow(a[i],g);
    }
    cnt.resize(sz(vec));
    val.resize(sz(vec));
    for(int x:vec){
	int id=lower_bound(vec.begin(),vec.end(),(p-1)/x)-vec.begin();
	for(int i=0;i<n;i++){
	    cnt[id]+=(Pow(a[i],x)==1);
	}
    }
    for(int i=sz(vec)-1;i>=0;i--){
	for(int j=i+1;j<sz(vec);j++){
	    if(vec[j]%vec[i]==0)
		cnt[i]-=cnt[j];
	}
    }
    ll ans=0;
    for(int i=0;i<sz(vec);i++){
	int c=cnt[i];
	for(int j=0;j<i;j++){
	    if(vec[i]%vec[j]==0)
		val[i]-=val[j],c+=cnt[j];
	}
	val[i]+=c>0;
	ans=(ans+1ll*((p-1)/vec[i])*val[i])%mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.