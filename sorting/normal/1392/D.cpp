#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

int n, iter;
string s;
pair<int, int> dp[k_N][4][4];

int get_dp(int pos, int two, int last){
    auto &[ans, solved] = dp[pos][two][last];
    if(pos == n + 2) return 0;
    if(solved == iter)
        return ans;

    solved = iter;
    ans = k_N;

    if(pos < n){
        if(last != 0){
            int new_last = (bool)(last & 2);
            ans = get_dp(pos + 1, two, new_last) + (s[pos] != 'L');
        }
        if(last != 3){
            int new_last = (bool)(last & 2) + 2;
            ans = min(ans, get_dp(pos + 1, two, new_last) + (s[pos] != 'R'));
        }
    }
    else if(pos == n){
        int x = two & 1;
        if(last == 3 && x == 1) ans = k_N;
        else if(last == 0 && x == 0) ans = k_N;
        else{
            int new_last = (bool)(last & 2) + x * 2;
            ans = get_dp(pos + 1, two, new_last);
        } 
    }
    else if(pos == n + 1){
        int x = (bool)(two & 2);
        if(last == 3 && x == 1) ans = k_N;
        else if(last == 0 && x == 0) ans = k_N;
        else{
            int new_last = (bool)(last & 2) + x * 2;
            ans = get_dp(pos + 1, two, new_last);
        }
    }

    return ans;
}

void solve(){
    cin >> n >> s;
    int ans = k_N;
    for(int i = 0; i < 4; ++i){
        int sum = 0;
        if(s[0] == 'R' != ((bool)(i & 1)))
            sum++;
        if(s[1] == 'R' != ((bool)(i & 2)))
            sum++;
        ans = min(ans, get_dp(2, i, i) + sum);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(iter = 1; iter <= t; ++iter) solve();
}