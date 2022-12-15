#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 400 + 3;
int MOD;

int n;
pair<int, bool> dp[N][N];
int f[N], inv_f[N], pw2[N];

int fast_pow(int base, int exp){
    int ans = 1;
    while(exp){
        if(exp & 1) ans = (ll)ans * base % MOD;
        base = (ll)base * base % MOD;
        exp >>= 1;
    }
    return ans;
}

int comb(int n, int k){
    return (ll)f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD;  
}

int solve(int pos, int moves){
    if(pos == n) return 0;
    if(pos == n + 1) return !moves;

    auto &[ans, solved] = dp[pos][moves];
    if(solved) return ans;

    ans = 0;
    solved = true;

    for(int i = 1; i <= min(n - pos, moves); ++i)
        ans = (ans + (ll)solve(pos + i + 1, moves - i) * comb(moves, i) % MOD * pw2[i - 1]) % MOD;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> MOD;
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
        f[i] = (ll)f[i - 1] * i % MOD;
    inv_f[n] = fast_pow(f[n], MOD - 2);
    for(int i = n - 1; i >= 0; --i)
        inv_f[i] = (ll)inv_f[i + 1] * (i + 1) % MOD;
    pw2[0] = 1;
    for(int i = 1; i <= n; ++i){
        pw2[i] = pw2[i - 1] << 1;
        if(pw2[i] >= MOD) pw2[i] -= MOD;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += solve(0, i);
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";
}