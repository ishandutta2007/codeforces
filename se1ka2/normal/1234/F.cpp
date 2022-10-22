#include <iostream>
#include <string>
using namespace std;

int b[1200000];
int dp[1200000];

int dfs(int bit, int i){
    if(b[bit]) return dp[bit] = i;
    if(dp[bit] != -1) return dp[bit];
    int res = 0;
    for(int j = 0; j < 20; j++){
        if(bit & (1 << j)){
            res = max(res, dfs(bit ^ (1 << j), i - 1));
        }
    }
    return dp[bit] = res;
}

int main()
{
    b[0] = 1;
    fill(dp, dp + (1 << 20), -1);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int bit = 0;
        for(int j = i; j >= 0; j--){
            if(bit & (1 << (s[j] - 'a'))) break;
            bit |= (1 << (s[j] - 'a'));
            b[bit] = 1;
        }
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << 20); bit++){
        if(b[bit]){
            int c = 0;
            for(int i = 0; i < 20; i++){
                if(bit & (1 << i)) c++;
            }
            ans = max(ans, c + dfs((1 << 20) - 1 - bit, 20 - c));
        }
    }
    cout << ans << endl;
}