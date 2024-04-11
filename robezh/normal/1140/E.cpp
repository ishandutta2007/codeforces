#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, mod = 998244353;

int n, k;
vector<int> nums[2];
ll dp[N][3];
ll pw[N];

ll solve(vector<int> &num) {
    ll res = 1;
    int n = num.size();
    int la = -1, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] == -1) {cnt++; continue;}
        if(cnt == 0) {la = num[i]; continue;}
        if(la == -1) res *= pw[cnt] % mod;
        else {
            if(num[i] == la) res *= (dp[cnt-1][1] + (k-2) * dp[cnt-1][2]) % mod;
            else res *= (dp[cnt-1][0] + (k - 2) * dp[cnt-1][2]) % mod;
        }
        res %= mod;
        la = num[i];
        cnt = 0;
    }
    if(la == -1) res *= pw[n-1] * k % mod;
    else if(cnt != 0) res *= (dp[cnt-1][0] + dp[cnt-1][1] + (k - 2) * dp[cnt-1][2]) % mod;
    res %= mod;
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(!nums[i%2].empty() && a != -1 && nums[i%2].back() == a) return !printf("0");
        nums[i%2].push_back(a);
    }
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = pw[i-1] * (k - 1) % mod;
    dp[0][1] = 1;
    if(k >= 3) dp[0][2] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][1] + (k - 2) * dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][0] + (k - 2) * dp[i-1][2]) % mod;
        if(k >= 3) dp[i][2] = (dp[i-1][0] + dp[i-1][1] + (k - 3) * dp[i-1][2]) % mod;
    }
//    cout << 1LL * (k-1) << " " << 1LL * k * (k-1) % mod << endl;
//    cout << solve(nums[0]) << " " << solve(nums[1]) << endl;
    ll res = solve(nums[0]) * solve(nums[1]) % mod;
    cout << res << endl;
}