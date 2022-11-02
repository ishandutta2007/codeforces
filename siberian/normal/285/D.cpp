#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 16;
const int MOD = 1e9 + 7;
bool used[MAXN];
bool have[MAXN];
ll ans;

void dfs(int pos, int len) {
    if (pos == len) {
        ans++;
        return;
    } 
    for (int i = 0; i < len; i++) {
        if (used[i]) continue;
        if (have[(pos + i) % len]) continue;
        used[i] = true;
        have[(pos + i) % len] = true;
        dfs(pos + 1, len);
        used[i] = false;
        have[(pos + i) % len] = false;
    }
}

int solve(int n) {
    ans = 0;
    used[0] = 1;
    have[0] = 1;
    dfs(1, n);
    ans = ans * n % MOD;
    for (int i = 1; i <= n; i++) {
        ans = ans * i;
        ans %= MOD;
    }
    return ans % MOD;
}

vector<int> fans {
    1, 
    18, 
    1800, 
    670320, 
    734832000, 
    890786230, 
    695720788, 
    150347555
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //for (int i = 1; i <= 15; i += 2) {
    //    cout << solve(i) << ", " << endl;
    //}
    int n;
    cin >> n;
    if (n & 1) {
        cout << fans[n / 2] << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}