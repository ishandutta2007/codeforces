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

const int maxn=5010,inf=1e9;

int dp[maxn],tw[maxn];
ll a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=inf;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	while((a[i]&1)==0) a[i]>>=1,tw[i]++;
	dp[i]=i;
	for(int j=0;j<i;j++){
	    if((i-tw[i])<=j && (j-i+tw[i])!=tw[j])continue;
	    if(a[j]%a[i]==0)	dp[i]=min(dp[i],i-j-1+dp[j]);
	}
	ans=min(ans,dp[i]+n-1-i);
    }
    cout<<ans<<endl;
    return 0;
}