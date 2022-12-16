// Can U hack it?

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
typedef long double ld;

const int maxn=2600;

ld dp[maxn][maxn][2];
pii p[maxn];

ld Dis(pii a,pii b){
    return sqrt(1ll*(a.F-b.F)*(a.F-b.F)+1ll*(a.S-b.S)*(a.S-b.S));
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
	cin>>p[i].F>>p[i].S;
    ld ans=0;
    for(int ln=2;ln<=n;ln++){
	for(int i=0;i<n;i++){
	    int j=(i+ln-1)%n;
	    dp[i][j][0]=max(Dis(p[i],p[(i+1)%n])+dp[(i+1)%n][j][0],Dis(p[i],p[j])+dp[(i+1)%n][j][1]);
	    dp[i][j][1]=max(Dis(p[(j-1+n)%n],p[j])+dp[i][(j-1+n)%n][1],Dis(p[i],p[j])+dp[i][(j-1+n)%n][0]);
	    ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
	}
    }
    cout<<setprecision(10)<<fixed<<ans<<endl;
}