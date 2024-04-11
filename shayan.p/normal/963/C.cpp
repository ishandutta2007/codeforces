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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll A[maxn],B[maxn],C[maxn];
vector<ll>v1,v2;

ll Div(ll n){
    ll ans=0;
    for(ll i=1;(i*i)<=n;i++){
	if(n%i==0)
	    ans+=(i*i==n?1:2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>A[i]>>B[i]>>C[i];
	v1.PB(A[i]);
	v2.PB(B[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    v1.resize(unique(v1.begin(),v1.end())-v1.begin());
    v2.resize(unique(v2.begin(),v2.end())-v2.begin());
    if(1ll*sz(v1)*sz(v2)!=n){
	return cout<<0<<endl,0;
    }
    int N=sz(v1),M=sz(v2);
    ll cnt[N+10][M+10];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
	int aa=lower_bound(v1.begin(),v1.end(),A[i])-v1.begin();
	int bb=lower_bound(v2.begin(),v2.end(),B[i])-v2.begin();
	cnt[aa][bb]=C[i];
    }
    ll GCD=0,LCM=1;
    for(int i=0;i<N;i++){
	GCD=__gcd(GCD,cnt[i][0]);
	ll g=0;
	for(int j=0;j<M;j++)
	    g=__gcd(g,cnt[i][j]);
	cnt[i][0]/=g;
    }
    for(int i=0;i<N;i++){
	ll x=__gcd(LCM,cnt[i][0]);
	x=LCM/x;
	if(cnt[i][0]>((GCD+x-1)/x))
	    return cout<<0<<endl,0;
	LCM=x*cnt[i][0];
	if(LCM>GCD)
	    return cout<<0<<endl,0;
    }
    if(GCD%LCM==0)
	return cout<<Div(GCD/LCM)<<endl,0;
    else
	return cout<<0<<endl,0;
}