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

const int maxn=19,maxt=(1<<18)+10;

double dp[maxt],p[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    cin>>p[i][j];
    dp[1]=1;
    for(int msk=2;msk<(1<<n);msk++){
	if(!bit(msk,0)) continue;
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
		if(bit(msk,i) && bit(msk,j)){
		    dp[msk]=max(dp[msk],p[i][j]*dp[msk ^ (1<<j)] + p[j][i] * dp[msk ^ (1<<i)] );
		}
	    }
	}
    }
    cout<<setprecision(10)<<fixed<<dp[(1<<n)-1]<<endl;
    return 0;
}