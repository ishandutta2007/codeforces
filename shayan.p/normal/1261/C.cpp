// Remember...

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

string s[maxn], ans[maxn];
int cnt[maxn], n, m;
vector<int> dp[maxn];

bool check(int mid){
    int k=2*mid+1;
    
    fill(cnt,cnt+m,0);
    
    if(k>n || k>m) return 0;
    
    for(int i=n-1;i>=0;i--){
	for(int j=0;j<m;j++){
	    if(dp[i][j]>=k) cnt[j]++;
	    if(i+k<n && dp[i+k][j]>=k) cnt[j]--;
	}
	int sm=0;
	for(int j=m-1;j>=0;j--){
	    sm+=cnt[j];
	    if(j+k<m) sm-=cnt[j+k];
	    if(s[i][j]=='X' && sm==0) return 0;
	}
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    cin>>n>>m;

    for(int i=0;i<n;i++){
	cin>>s[i];
	for(int j=0;j<m;j++)
	    ans[i]+='.';
	dp[i].resize(m);
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(s[i][j]=='.'){
		dp[i][j]=0;
	    }
	    else{
		dp[i][j]= 1 + min( i==0 ? 0 : dp[i-1][j], j==0 ? 0 : dp[i][j-1] );
		if(s[i - dp[i][j] +1][j - dp[i][j]+1] == '.') dp[i][j]--;
	    }
	}
    }
    
    int l=0, r=maxn;
    while(r-l>1){
	int mid=(l+r)>>1;
	if(check(mid)) l=mid;
	else r=mid;
    }
    
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(dp[i][j]>=(2*l+1))
		ans[i-l][j-l]='X';
	}
    }
    cout<<l<<"\n";
    for(int i=0;i<n;i++)
	cout<<ans[i]<<"\n";
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")