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

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

bool dp[2][maxn];
set<string>st;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    dp[0][sz(s)-2]=dp[1][sz(s)-3]=1;
    for(int i=sz(s)-4;i>=0;i--){
	dp[0][i]=(dp[0][i+2] && s.substr(i,2)!=s.substr(i+2,2)) || dp[1][i+2];
	dp[1][i]=(dp[1][i+3] && s.substr(i,3)!=s.substr(i+3,3)) || dp[0][i+3];
    }
    for(int i=5;i<sz(s);i++){
	if(dp[0][i]) st.insert(s.substr(i,2));
	if(dp[1][i]) st.insert(s.substr(i,3));
    }
    cout<<sz(st)<<"\n";
    for(auto x:st)
	cout<<x<<"\n";
    cout<<endl;
    return 0;
}