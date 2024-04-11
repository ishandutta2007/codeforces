#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 100000 + 10;
LL dp[N][12],p[N][12],vis[N][12];int n;
string s[N],str;
void dfs(int dep,int x) {
    if(vis[dep][x]) return;
    if(dep==n+1) {
        dp[dep][x]=x, p[dep][x]=10;
        return;
    }
    vis[dep][x]=1;

    if(s[dep][0]!='0'+x) {
        dfs(dep+1,x); 
        dp[dep][x] = dp[dep+1][x]; p[dep][x] = p[dep+1][x];
        return;
    }      
    int len = s[dep].length(); 
    dp[dep][x] = 0, p[dep][x] = 1;
    
    for(int i=len-1;i>=3;i--) {
        dfs(dep+1,s[dep][i]-'0');
        dp[dep][x] += dp[dep+1][s[dep][i]-'0'] * p[dep][x]; dp[dep][x] %= MOD;
        p[dep][x] = p[dep][x] * p[dep+1][s[dep][i]-'0'] % MOD;
    }

}

int main() {
    cin.sync_with_stdio(false);
    cin>>str>>n; ++n;
    s[1]="1->"+str;
    for(int i=2;i<=n;i++) cin>>s[i];
    dfs(1,1); cout<<dp[1][1]<<endl;
}