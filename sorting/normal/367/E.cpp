#include <bits/stdc++.h>

using namespace std;

const int k_N = 400;
const int k_Mod = 1e9 + 7;

int n, m, x;
int dp[2][k_N][k_N];

inline void fix(int &x){
    x = (x >= k_Mod) ? (x - k_Mod) : x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    if(n > m){
        cout << "0\n";
        return 0;
    }

    dp[1][0][0] = 1;
    for(int i = 1; i <= m; ++i){
        int curr = i & 1, nxt = (i + 1) & 1;
        for(int l = 0; l <= n; ++l){
            for(int r = l; r <= n; ++r){
                int &answer = dp[curr][l][r];
                //cout << answer << " = " << i << " " << l << " " << r << endl; 
                
                if(r != n){
                    dp[nxt][l][r + 1] += answer;
                    fix(dp[nxt][l][r + 1]);

                    dp[nxt][l + 1][r + 1] += answer;
                    fix(dp[nxt][l + 1][r + 1]);
                }
                if(i == x)
                    continue;

                if(l != r){
                    dp[nxt][l + 1][r] += answer;
                    fix(dp[nxt][l + 1][r]);
                }
                dp[nxt][l][r] += answer;
                fix(dp[nxt][l][r]);
            }
        }

        for(int l = 0; l <= n; ++l)
            for(int r = l; r <= n; ++r)
                dp[curr][l][r] = 0;
    }

    long long answer = dp[(m + 1) & 1][n][n];
    for(int i = 1; i <= n; ++i){
        answer *= i;
        answer %= k_Mod;
    }

    cout << answer << "\n";
}