// Jump, and you will find out how to unfold your wings as you fall.

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

int dp[12][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    ll ans=0;
    for(int i=1;i<=sz(s);i++){
	int x=s[i-1]-'0';
	for(int j=x+1;j<11;j++){
	    dp[(j*(j-1)*6 + x + 10)%11][i]+=dp[j][i-1];
	}
	if(x!=0){
	    dp[x][i]++;
	}
	for(int j=0;j<11;j++){
	    ans+=dp[j][i];
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.