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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>dv[maxn],pp[maxn];
int prob[maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1)
	    ans=1ll*ans*a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j+=i)
	    dv[j].PB(i);
    }
    int ans=1,iv=Pow(n,mod-2);
    for(int i=n;i>1;i--){
	prob[i]=(prob[i]+iv)%mod;
	pp[i].resize(sz(dv[i]));
	for(int j=sz(dv[i])-1;j>=0;j--){
	    pp[i][j]=n/dv[i][j];
	    for(int k=j+1;k<sz(dv[i]);k++){
		if(dv[i][k]%dv[i][j]==0)
		    pp[i][j]-=pp[i][k];
	    }
	}
	int bad=1ll*pp[i].back()*iv %mod;
	for(int j=0;j<sz(dv[i])-1;j++){
	    int ed=1ll*prob[i]*pp[i][j] %mod *iv %mod;
	    int num=1ll*ed * Pow(1-bad,mod-2) %mod;
	    ans=(ans+num)%mod;
	    prob[dv[i][j]]=(prob[dv[i][j]]+num)%mod;
	}
	ans=(1ll*ans+1ll*prob[i]*(Pow(1-bad,mod-2)-1) )%mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.