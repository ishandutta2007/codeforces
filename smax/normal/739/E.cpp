#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> pa(n), pb(n);
    for (int i=0; i<n; i++) {
        double x;
        cin >> x;
        pa[i] = (long long) round(x * MAX) * MAX;
    }
    for (int i=0; i<n; i++) {
        double x;
        cin >> x;
        pb[i] = (long long) round(x * MAX) * MAX;
    }

    vector<long long> pab(n);
    for (int i=0; i<n; i++)
        pab[i] = pa[i] + pb[i] - (pa[i] / MAX) * (pb[i] / MAX);

    auto ckmax = [] (long long &a, long long b) -> bool {
        return a < b ? a = b, true : false;
    };

    auto solve = [&] (long long ca, long long cb) -> pair<long long, pair<bool, bool>> {
        vector<long long> dp(n + 1);
        vector<int> cntA(n + 1), cntB(n + 1), cntE(n + 1);
        for (int i=0; i<n; i++) {
            dp[i+1] = dp[i];
            cntA[i+1] = cntA[i];
            cntB[i+1] = cntB[i];
            cntE[i+1] = cntE[i];
            if (ckmax(dp[i+1], dp[i] + pa[i] - ca)) {
                cntA[i+1] = cntA[i] + 1;
                cntB[i+1] = cntB[i];
            }
            if (ckmax(dp[i+1], dp[i] + pb[i] - cb)) {
                cntA[i+1] = cntA[i];
                cntB[i+1] = cntB[i] + 1;
            }
            if (ckmax(dp[i+1], dp[i] + pab[i] - ca - cb)) {
                cntA[i+1] = cntA[i] + 1;
                cntB[i+1] = cntB[i] + 1;
            }
            if (dp[i+1] > dp[i] && dp[i+1] == dp[i] + pa[i] - ca && dp[i+1] == dp[i] + pb[i] - cb) {
                cntA[i+1] = cntA[i];
                cntB[i+1] = cntB[i];
                cntE[i+1] = cntE[i] + 1;
            }
        }
        return {dp[n] + a * ca + b * cb, {cntB[n] <= b, cntA[n] <= a && cntB[n] <= b && cntA[n] + cntB[n] + cntE[n] <= a + b}};
    };

    long long la = 0, ra = MAX * MAX + 5, lb, rb;
    while (la < ra) {
        long long ma = (la + ra) / 2;
        lb = 0, rb = MAX * MAX + 5;
        while (lb < rb) {
            long long mb = (lb + rb) / 2;
            if (solve(ma, mb).second.first)
                rb = mb;
            else
                lb = mb + 1;
        }
        if (solve(ma, rb).second.second)
            ra = ma;
        else
            la = ma + 1;
    }
    lb = 0, rb = MAX * MAX + 5;
    while (lb < rb) {
        long long mb = (lb + rb) / 2;
        if (solve(ra, mb).second.first)
            rb = mb;
        else
            lb = mb + 1;
    }
    cout << fixed << setprecision(10) << (double) solve(ra, rb).first / (MAX * MAX) << "\n";

    return 0;
}