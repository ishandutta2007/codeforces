// Faster!

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

const int maxn=55,inf=5e8;

int dp[maxn][maxn][maxn];
int L[maxn],R[maxn],x[maxn],c[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,h,q;cin>>n>>h>>q;
    for(int i=0;i<q;i++){
	cin>>L[i]>>R[i]>>x[i]>>c[i];
    }
    for(int r=1;r<=n;r++){
	for(int l=r;l>=1;l--){
	    for(int w=1;w<=h;w++){
		dp[l][r][w]=dp[l][r][w-1];
		for(int pos=l;pos<=r;pos++){
		    int num=0;
		    for(int id=0;id<q;id++){
			if(l<=L[id] && R[id]<=r && L[id]<=pos && pos<=R[id] && x[id]<w) num+=c[id];
		    }
		    dp[l][r][w]=max(dp[l][r][w],dp[l][pos-1][w]+dp[pos+1][r][w]-num+(w*w));
		}
	    }
	}
    }
    return cout<<dp[1][n][h]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.