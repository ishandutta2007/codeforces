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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

ll dp[maxn][3][3];// avali // dovomi
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<maxn;i++)
	for(int j=0;j<3;j++)
	    for(int k=0;k<3;k++)
		dp[i][j][k]=-inf;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	a[--x]++;
    }
    for(int j=0;j<=min(2,a[0]);j++){
	dp[0][j][0]=(a[0]-j)/3;
    }
    for(int i=1;i<m;i++){
	for(int j=0;j<3;j++){
	    for(int k=0;k<3;k++){
		for(int w=0;w<3;w++){
		    if(j+k+w>a[i]) continue;
		    dp[i][j][k]=max(dp[i][j][k],w+((a[i]-j-k-w)/3)+dp[i-1][k][w]);
		}
	    }
	}
    }
    return cout<<max(ll(0),dp[m-1][0][0])<<endl,0;
}