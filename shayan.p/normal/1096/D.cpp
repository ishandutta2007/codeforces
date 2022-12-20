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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

ll dp[4][maxn],a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=1;i<=n;i++)
	dp[0][i]=dp[0][i-1]+(s[i-1]=='h'?a[i-1]:0);
    for(int i=1;i<=n;i++)
	dp[1][i]=(s[i-1]=='a'?min(dp[0][i-1],dp[1][i-1]+a[i-1]):dp[1][i-1]);
    for(int i=1;i<=n;i++)
	dp[2][i]=(s[i-1]=='r'?min(dp[1][i-1],dp[2][i-1]+a[i-1]):dp[2][i-1]);
    for(int i=1;i<=n;i++)
	dp[3][i]=(s[i-1]=='d'?min(dp[2][i-1],dp[3][i-1]+a[i-1]):dp[3][i-1]);
    cout<<dp[3][n]<<endl;
    return 0;
}