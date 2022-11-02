#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int BUBEN = 30;
const int N = 2e5 + 10;
int p, m;
int n;
string a[N];

string ans;
int fans = 0;

set<int> used;

int getMask(int pos, int needMask) {
    int mask = 0;
    int now = 0;
    for (int i = 0; i < m; ++i) {
        if (a[pos][i] == '0') continue;
        if (a[needMask][i] == '1') {
            mask ^= (1 << now);
        }
        ++now;
    }
    return mask;
}

const int P = 15;
int dp[1 << P];

void add(int mask, int cnt) {
    // for (int submask = 0; submask < (1 << cnt); ++submask) {
    //     if ((mask | submask) == mask) {
    //         dp[submask]++;
    //         // cerr << "submask = " << submask << " mask = " << mask << endl;
    //     }
    // }
    mask = ((~mask) & ((1 << cnt) - 1));
    dp[mask]++;
}

int F[1 << P];

void calc(int cnt) {
    for(int i = 0; i<(1<<cnt); ++i)
        F[i] = dp[i];
    for(int i = 0;i < cnt; ++i) for(int mask = 0; mask < (1<<cnt); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }
    for (int i = 0; i < (1 << cnt); ++i) {
        int mask = ((~i) & ((1 << cnt) - 1));
        dp[mask] = F[i];
    }
}

void relaxAns(int pos, int, int mask) {
    int have = __builtin_popcount(mask);
    if (fans >= have) return;
    fans = have;
    int now = 0;
    for (int i = 0; i < m; ++i) {
        if (a[pos][i] == '0') {
            ans[i] = '0';
        } else {
            if ((mask >> now) & 1) {
                ans[i] = '1';
            } else {
                ans[i] = '0';
            }
            ++now;
        }
    }
}

void relax() {
    if (used.size() == n) return;
    int pos = (ull)rnd() % n;
    while (used.count(pos)) pos = (ull)rnd() % n;
    used.insert(pos);
    // int pos = 1;
    int cnt = 0;
    for (auto i : a[pos]) cnt += i == '1';
    // cerr << "cnt = " << cnt << endl;
    if (cnt == 0) return;
    fill(dp, dp + (1 << cnt), 0);
    for (int i = 0; i < n; ++i) {
        int mask = getMask(pos, i);
        // cerr << "getMask = " << mask << endl;
        add(mask, cnt);
    }
    calc(cnt);
    // cerr << "dp = " << endl;
    // for (int i = 0; i < (1 << cnt); ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    for (int mask = 0; mask < (1 << cnt); ++mask) {
        if (dp[mask] < (n + 1) / 2) continue;
        // cerr << "mask = " << mask << endl;
        relaxAns(pos, cnt, mask);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ans = "";
    for (int i = 0; i < m; ++i) {
        ans += "0";
    }
    for (int it = 0; it < BUBEN; ++it) {
        relax();
    }
    cout << ans << endl;
    return 0;
}