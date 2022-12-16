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
typedef pair<pii,pii> pi4;

const int maxn=1010;

vector<pi4>v[maxn];// w,s  ,  r,vl
vector<int>DP[maxn][maxn];
int dp[maxn][maxn],pt[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,S;cin>>n>>S;
    for(int i=0;i<n;i++){
	int l,r,w,s,vl;cin>>l>>r>>w>>s>>vl;
	v[l].PB({{w,s},{r,vl}});
    }
    for(int i=0;i<2*n;i++){
	sort(v[i].begin(),v[i].end(),[](pi4 a,pi4 b){ return a.S.F<b.S.F; });
    }
    for(int r=0;r<2*n;r++){
	for(int l=r-1;l>=0;l--){
	    for(int s=0;s<=S;s++){
		dp[l][s]=dp[l+1][s];
		for(int k=0;k<pt[l];k++)
		    dp[l][s]=max(dp[l][s] , DP[l][s][k] + dp[ v[l][k].S.F ][s]);
		if(pt[l]<sz(v[l]) && v[l][pt[l]].S.F==r){
		    int _w=v[l][pt[l]].F.F,_s=v[l][pt[l]].F.S,vl=v[l][pt[l]].S.S;
		    _s=min(_s,s-_w);
		    if(_s>=0){
			dp[l][s]=max(dp[l][s],dp[l+1][_s]+vl);
			for(int k=0;k<pt[l];k++)
			    dp[l][s]=max(dp[l][s] , DP[l][_s][k] + dp[ v[l][k].S.F ][_s] + vl);
		    }
		    DP[l][s].PB(dp[l][s]);
		}
	    }
	    if(pt[l]<sz(v[l]) && v[l][pt[l]].S.F==r) pt[l]++;
	}
    }
    return cout<<dp[0][S]<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.