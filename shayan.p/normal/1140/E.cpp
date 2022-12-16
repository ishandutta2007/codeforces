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

const int maxn=1e5+10,mod=998244353;

int n,k;
int dp1[maxn],dp2[maxn];

int solve(vector<int>&v){
    if(v.empty()) return 1;
    ll ans=1;
    int cnt=0,lst=-1;
    for(int x:v){
	if(x==-1){
	    cnt++;
	}
	else{
	    if(cnt==0 && lst==x){
		return 0;
	    }
	    if(cnt>0){
		if(lst==-1) ans=1ll*ans*(1ll*dp1[cnt-1]+1ll*(k-1)*dp2[cnt-1] %mod) %mod;
		else ans=1ll*ans*(lst==x ? dp1[cnt] : dp2[cnt] ) %mod;
	    }
	    lst=x;
	    cnt=0;
	}
    }
    if(lst==-1){
	if(cnt==1) return k;
	return (1ll*dp1[cnt-2]*k + 1ll*dp2[cnt-2]*k %mod * (k-1))%mod;
    }
    if(cnt==0) return ans;
    ans=1ll*ans*(1ll*dp1[cnt-1] + 1ll*(k-1)*dp2[cnt-1] %mod) %mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;

    dp1[0]=0,dp2[0]=1;
    for(int i=1;i<maxn;i++){
	dp1[i]=1ll*(k-1)*dp2[i-1] %mod;
	dp2[i]=(1ll*(k-2)*dp2[i-1]+ 1ll*dp1[i-1])%mod;
    }
    vector<int>v[2];
    for(int i=0;i<n;i++){
	int x;cin>>x;
	v[i&1].PB(x);
    }
    return cout<<1ll*solve(v[0])*solve(v[1]) %mod<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.