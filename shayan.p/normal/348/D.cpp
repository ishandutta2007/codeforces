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

const int maxn=3010,mod=1e9+7;
const ll inf=1e18;

string s[maxn];
int dp[maxn][maxn],n,m;

void calc(int a,int b){
    memset(dp,0,sizeof dp);
    dp[a][b]=s[a][b]=='.';
    for(int sm=a+b+1;sm<n+m;sm++){
	for(int i=0;i<n;i++){
	    int j=sm-i;
	    if(j<0 || j>=m || s[i][j]=='#') continue;
	    dp[i][j]=((i==0?0:dp[i-1][j])+(j==0?0:dp[i][j-1]))%mod;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>s[i];
    calc(1,0);
    int A=dp[n-1][m-2],B=dp[n-2][m-1];
    calc(0,1);
    int C=dp[n-1][m-2],D=dp[n-2][m-1];
    int ans=(1ll*A*D-1ll*B*C)%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}