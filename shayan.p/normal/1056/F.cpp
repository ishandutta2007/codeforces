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
typedef long double ld;

const int M1=110,M2=1010;
const ld eps=1e-9,inf=1e18;

ld dp[2][M1][M2];
pii p[M1];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    int q;cin>>q;
    while(q--){
	for(int i=0;i<2;i++)
	    for(int j=0;j<M1;j++)
		for(int k=0;k<M2;k++)
		dp[i][j][k]=inf;
	int n;cin>>n;
	ld c,t;cin>>c>>t;
	for(int i=0;i<n;i++){
	    cin>>p[i].F>>p[i].S;
	}
	sort(p,p+n);
	dp[1][0][0]=dp[0][0][0]=0;
	for(int i=0;i<n;i++){
	    int o=i&1,O=1-o;
	    for(int j=1;j<=i+1;j++){
		for(int k=0;k<=10*j;k++){
		    if(k<p[i].S || dp[O][j-1][k-p[i].S]==inf){
			dp[o][j][k]=dp[O][j][k];
			continue;
		    }
		    dp[o][j][k]=min(dp[O][j][k],(dp[O][j-1][k-p[i].S]+p[i].F)*(ld(10)/9));
		}
	    }
	}
	int nw=(n+1)&1,ans=0;
	for(int i=1;i<=n;i++){
	    ld t0=max(ld(0),(t-10*i-(1/c))/2);
	    ld x=(t-t0-10*i)*(1+t0*c);
	    for(int j=0;j<=10*i;j++){
		if(dp[nw][i][j]==inf) continue;		
		if(x-dp[nw][i][j]>=-eps)
		    ans=max(ans,j);
	    }
	}
	cout<<ans<<endl;
    }
    return 0;
}