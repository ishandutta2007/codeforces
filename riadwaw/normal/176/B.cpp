#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}\


int dp[2][1010];
int sum[101010];
const int mod = 1000000007;
void solve() {
    string s,e;
    cin>>s>>e;
    int k;
    cin>>k;
    int n=s.size();
    dp[0][0] = 1;
    sum[0] = 1;
    for(int len = 1;len <= k;++len){
        for(int j = 0; j<n; ++j){
            dp[len%2][j] = (sum[len-1] - dp[(len-1)%2][j] + mod) %mod;
            //cout<<dp[len%2][j]<<' ';
            sum[len] += dp[len%2][j];
            sum[len] %= mod;
        }
        //cout<<endl;
    }
    li ans = 0;
    for(int i=0;i<n;++i){
        bool ok = true;
        for(int j=0;j<n;++j){
            if(e[(i+j)%n]!=s[j]){
                ok =false;
                break;
            }
        }
        if(ok){
            ans += dp[k%2][i];
            ans %= mod;
        }
    }
    
    cout<<ans;
}