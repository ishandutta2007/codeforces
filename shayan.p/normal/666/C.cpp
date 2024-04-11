// Phoenix

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

const int maxn=1e5+10,mod=1e9+7;

int fac[maxn],ifac[maxn],ans[maxn],pw[maxn],pwi[maxn];
vector<pii> v[maxn];

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

inline int C(int n,int k){
    if(n<k) return 0;
    return 1ll*fac[n]*ifac[k] %mod *ifac[n-k] %mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;i++)
	fac[i]=1ll*i*fac[i-1] %mod;
    ifac[maxn-1]=Pow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	ifac[i]=1ll*(i+1)*ifac[i+1] %mod;
    pw[0]=1;
    for(int i=1;i<maxn;i++)
	pw[i]=25ll*pw[i-1] %mod;
    pwi[maxn-1]=Pow(pw[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
	pwi[i]=25ll*pwi[i+1] %mod;

    int q;cin>>q;
    string s;cin>>s;
    int ss=sz(s),c=0;
    while(q--){
	int task;cin>>task;
	if(task==1){
	    cin>>s;
	    ss=sz(s);
	}
	else{
	    int x;cin>>x;
	    v[ss].PB({x,c++});
	}	    
    }
    for(int ln=1;ln<maxn;ln++){
	sort(v[ln].begin(),v[ln].end());
	int A=pwi[ln],pt=0;
	while(pt<sz(v[ln]) && v[ln][pt].F<ln)
	    pt++;
	for(int i=ln;i<maxn;i++){
	    if(pt==sz(v[ln])) break;
	    while(pt<sz(v[ln]) && v[ln][pt].F==i) ans[v[ln][pt].S]=1ll*A*pw[i] %mod,pt++;
	    A=1ll*(26ll*A+1ll*C(i,ln-1)*pwi[ln-1])%mod *pwi[1] %mod;
	}
    }
    for(int i=0;i<c;i++){
	if(ans[i]<0) ans[i]+=mod;
	cout<<ans[i]<<"\n";
    }
    return 0;
}