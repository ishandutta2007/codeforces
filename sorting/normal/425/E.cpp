#include <bits/stdc++.h>

using namespace std;

const long long k_Mod = 1e9 + 7;
const int k_N = 500 + 3;

long long dp[2][k_N][k_N];
long long power_of_2[k_N];
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    power_of_2[0] = 1;
    for(int i = 1; i < k_N; ++i)
        power_of_2[i] = (power_of_2[i - 1] * 2) % k_Mod;

    for(int start_index = 0; start_index <= n; ++start_index)
        for(int intervals_remaining = 0; intervals_remaining <= k; ++intervals_remaining)
            dp[(n & 1)][start_index][intervals_remaining] = !intervals_remaining;

    for(int right = n - 1; right >= 0; --right){
        bool next_index = (right + 1) & 1;
        bool current_index = right & 1;

        for(int start_index = 0; start_index <= right; ++start_index){

            {int intervals_remaining = 0;
                long long &answer = dp[current_index][start_index][intervals_remaining];
                answer = dp[next_index][start_index][intervals_remaining] * power_of_2[start_index] % k_Mod;
            }

            for(int intervals_remaining = 1; intervals_remaining <= k; ++intervals_remaining){
                long long &answer = dp[current_index][start_index][intervals_remaining];
                
                answer = dp[next_index][right + 1][intervals_remaining - 1] * (power_of_2[right - start_index + 1] - 1 + k_Mod) % k_Mod * power_of_2[start_index] % k_Mod;
                answer += dp[next_index][start_index][intervals_remaining] * power_of_2[start_index] % k_Mod;
                answer = (answer >= k_Mod) ? (answer - k_Mod) : answer;
            }
        }
    }

    cout << dp[0][0][k] << "\n";
}