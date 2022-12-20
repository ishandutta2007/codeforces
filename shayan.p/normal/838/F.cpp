// Wanna Hack? GL...

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
typedef long double ld;/////

const int maxn=1e4+10,Six=1e6;

ld dp[maxn],f[maxn],C[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x;cin>>n>>x;
    ld c=ld(x)/Six;
    C[0]=1;
    for(int i=1;i<=n;i++){
	for(int j=i;j>=1;j--)
	    C[j]+=C[j-1];
    }
    for(int i=0;i<=n;i++){
	cin>>f[i];
	if(f[i]==0) f[i]=1;
	else f[i]*=1e20;
	f[i]/=C[i];
    }
    for(int tot=n-1;tot>=0;tot--){
	for(int i=0;i<=tot;i++){
	    f[i]+=f[i+1];
	    dp[i]=max(ld(0),dp[i] -c + (f[i+1]/f[i])*(dp[i+1]-dp[i]+1));
	}
    }
    return cout<<setprecision(10)<<fixed<<dp[0]<<endl,0;
}