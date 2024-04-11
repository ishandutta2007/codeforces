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

using namespace std;
void solve();
void prec();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    prec();
    cin>>t;
    while(t--)
        solve();
    return 0;
}
string s;
const int mod = 1000000007;
li dp[111][3000];

void prec(){
    dp[0][0] = 1;
    for(int i=1;i<=105;++i){
        for(int cur = 0; cur <=28*i;++cur){
            for(int prev = max(0, cur-25);prev<=cur;++prev){
                dp[i][cur] += dp[i-1][prev];
                dp[i][cur] %= mod;
            }
        }
    }
}
void solve(){
    cin>>s;
    int sum = 0;
    for(int i=0;i<(int)s.length();++i){
        sum+=s[i]-'a';
    }
    
    cout<<(dp[s.length()][sum]-1)%mod<<'\n';
    
    
    
}