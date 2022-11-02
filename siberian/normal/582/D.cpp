#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

const int N = 4000;

int p, power;
string s;
vector<int> now;

int mod(vector<int>& now, int p) {
    ll ans = 0;
    for (auto i : now) {
        ans *= 10;
        ans += i;
        ans %= p;
    }  
    vector<int> fans;
    ll val = 0;
    for (auto i : now) {
        val *= 10;
        val += i;
        if (val >= p) {
            fans.push_back(val / p);
            val %= p;
        } else if (!fans.empty()) {
            fans.push_back(0);
        }
    }  
    now = fans;
    return ans;
}

vector<int> a;
int n;

void buildA() {
    while (!now.empty()) {
        a.push_back(mod(now, p));
    }
    reverse(all(a));
    n = a.size();
}

int dp[N][N][2][2];

int calcEq(int maxN, int hasAdd, int needAdd) {
    if (maxN < 0) return 0;
    int c = maxN + hasAdd * p - needAdd;
    int maxK = min(c, p - 1);
    int minK = max(c - p + 1, 0); 
    return max(0, maxK - minK + 1);
}

void myAssert(bool x) {
    while (!x) {}
}

int calc(int maxN, int hasAdd, int needAdd) {
    if (maxN < 0) return 0;
    int ans = 0;
    int c = hasAdd * p - needAdd;
    int maxK = min(c, p - 1);
    int minVal = calcEq(0, hasAdd, needAdd);
    int len = min(maxN, p - 1 - maxK);
    ans = add(ans, add(mul(minVal, len + 1), (ll)len * (len + 1) / 2 % MOD));
    if (len != maxN) {
        int n = len + 1;
        int c = hasAdd * p - needAdd + n;
        int maxK = min(c, p - 1);
        int maxVal = calcEq(n, hasAdd, needAdd);
        int len = maxN - n;
        ans = add(ans, sub(mul(maxVal, maxN - n + 1), (ll)len * (len + 1) / 2 % MOD));
    }
    return ans;
}

void calcDp() {
    if (power >= N) {
        cout << "0\n";
        exit(0);
    }
    dp[0][0][1][0] = 1;
    for (int pref = 0; pref <= n; ++pref) {
        for (int cnt = 0; cnt < N - 1; ++cnt) {
            for (int eq = 0; eq <= 1; ++eq) {
                for (int fadd = 0; fadd <= 1; ++fadd) {
                    int val = dp[pref][cnt][eq][fadd];
                    if (!val) continue;
                    if (pref == n) continue;
                    for (int nxtAdd = 0; nxtAdd <= 1; ++nxtAdd) {
                        int nxtCnt = min(cnt + nxtAdd, power);
                        if (eq) {
                            {
                                int& nxt = dp[pref + 1][nxtCnt][0][nxtAdd];
                                nxt = add(nxt, mul(calc(a[pref] - 1, fadd, nxtAdd), val));
                            }
                            {
                                int& nxt = dp[pref + 1][nxtCnt][1][nxtAdd];
                                nxt = add(nxt, mul(calcEq(a[pref], fadd, nxtAdd), val));
                            }
                        } else {
                            int& nxt = dp[pref + 1][nxtCnt][0][nxtAdd];
                            nxt = add(nxt, mul(calc(p - 1, fadd, nxtAdd), val));
                        }
                    }
                }
            }
        }
    }
}

int ans;

void calcAns() {
    ans = 0;
    for (int eq = 0; eq <= 1; ++eq) {
        ans = add(ans, dp[n][power][eq][0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> p >> power;
    cin >> s;
    for (auto i : s) {
        now.push_back(i - '0');
    }
    // reverse(all(now));
    buildA();
    calcDp();
    calcAns();
    cout << ans << endl;
    return 0;
}