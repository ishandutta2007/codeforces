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

const int maxn=1e7+10,mod=1e9+7;
const ll inf=1e18;

ll dp[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x,y;cin>>n>>x>>y;
    dp[1]=x;
    for(int i=2;i<=n;i++){
	if(i&1) dp[i]=min(dp[(i+1)>>1]+x+y,dp[i-1]+x);
	else dp[i]=min(dp[i>>1]+y,dp[i-1]+x);
    }
    cout<<dp[n]<<endl;
}