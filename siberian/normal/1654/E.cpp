#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 1e5 + 10;
const int B = 125;
int n;
int a[N];
int dp[N];
int cnt[N + N];

int best[N * B * 2 + 2 * N];

int solveSmall(int d) {
    // unordered_map<int, int> best;
    // best.reserve(n);
    // best.max_load_factor(0.25);
    fill(dp, dp + n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = best[a[i] - d * i + N * B + N] + 1;
        // auto it = best.find(a[i] - d * i);
        // if (it != best.end()) {
        //     chkmax(dp[i], it->second + 1);
        // }
        chkmax(best[a[i] - d * i + N * B + N], dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        best[a[i] - d * i + N * B + N] = 0;
    }
    return n - (*max_element(dp, dp + n));
}

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int val[N];

int solveBig(int from) {
    int ans = 0;
    for (int i = from + 1; i < n && (i - from) * (B + 1) <= N; ++i) {
        val[i] = INT_MAX;
        if (abs(a[i] - a[from]) % (i - from)) continue;
        val[i] = sign(a[i] - a[from]) * abs(a[i] - a[from]) / (i - from) + N;
        cnt[val[i]]++;
        chkmax(ans, cnt[val[i]] + 1);
    }

    for (int i = from + 1; i < n && (i - from) * (B + 1) <= N; ++i) {
        if (val[i] == INT_MAX) continue;
        cnt[val[i]]--;
    }
    return n - ans;
}

ld cur = 0;

void outTime() {
    cerr << "time: " << (ld)clock() / CLOCKS_PER_SEC - cur << endl;
    cur = (ld)clock() / CLOCKS_PER_SEC;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = n - 1;
    for (int delta = -B; delta <= B; ++delta) {
        chkmin(ans, solveSmall(delta));
    }
    outTime();
    for (int pos = 0; pos < n; ++pos) {
        chkmin(ans, solveBig(pos));
    }
    outTime();
    cout << ans << endl;
    return 0;
}