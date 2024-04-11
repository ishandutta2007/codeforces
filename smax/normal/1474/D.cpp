#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        n++;
        a.push_back(0);

        vector<long long> pSum(n);
        vector<vector<long long>> pMx(n, vector<long long>(2)), pMn(n, vector<long long>(2));
        for (int i=0; i<n; i++) {
            pSum[i] = (i % 2 ? -1 : 1) * a[i] + (i > 0 ? pSum[i-1] : 0);
            for (int j=0; j<2; j++) {
                pMx[i][j] = max(i % 2 == j ? pSum[i] : LLONG_MIN, i > 0 ? pMx[i-1][j] : LLONG_MIN);
                pMn[i][j] = min(i % 2 == j ? pSum[i] : LLONG_MAX, i > 0 ? pMn[i-1][j] : LLONG_MAX);
            }
        }
        vector<vector<long long>> sMx(n, vector<long long>(2)), sMn(n, vector<long long>(2));
        for (int i=n-1; i>=0; i--)
            for (int j=0; j<2; j++) {
                sMx[i][j] = max(i % 2 == j ? pSum[i] : LLONG_MIN, i + 1 < n ? sMx[i+1][j] : LLONG_MIN);
                sMn[i][j] = min(i % 2 == j ? pSum[i] : LLONG_MAX, i + 1 < n ? sMn[i+1][j] : LLONG_MAX);
            }

        auto check = [&] (int i) {
            if (i % 2) {
                // a_0 - a_1 + a_2 - ... + a_{i-1} <= a_i
                if (i > 0 && pSum[i-1] > a[i])
                    return false;
                // a_0 - a_1 + a_2 - ... - a_i + ... + a_k <= a_{k+1}
                // [a_0 - a_1 + a_2 - ... + a_{i-1}] + [a_{i+1} - a_{i+2} + ... + a_k - a_{k+1}] <= a_i
                // sMx <= 0
                if (i + 1 < n && sMx[i+1][1] > 0)
                    return false;
                // -[a_0 - a_1 + a_2 - ... - a_i + ... - a_k] <= a_{k+1}
                // a_0 - a_1 + a_2 - ... - a_i + ... - a_k >= -a_{k+1}
                // sMn >= 0
                if (i + 1 < n && sMn[i+1][0] < 0)
                    return false;
            } else {
                // -[a_0 - a_1 + a_2 - ... - a_{i-1}] <= a_i
                // a_0 - a_1 + a_2 - ... - a_{i+1} >= -a_i
                if (i > 0 && pSum[i-1] < -a[i])
                    return false;
                // a_0 - a_1 + a_2 - ... + a_i + ... + a_k <= a_{k+1}
                // [a_0 - a_1 + a_2 - ... - a_{i-1}] + [-a_{i+1} + a_{i+2} - ... + a_k - a_{k+1}] <= -a_i
                // sMx <= 0
                if (i + 1 < n && sMx[i+1][1] > 0)
                    return false;
                // -[a_0 - a_1 + a_2 - ... + a_i + ... - a_k] <= a_{k+1}
                // a_0 - a_1 + a_2 - ... + a_i + ... - a_k >= -a_{k+1}
                // sMn >= 0
                if (i + 1 < n && sMn[i+1][0] < 0)
                    return false;
            }
            return true;
        };

        bool ok = true;
        for (int i=0; i<n; i++)
            ok &= check(i);
        if (ok) {
            cout << "YES\n";
            continue;
        }

        DEBUG(pSum, sMn[1][0])
        // ODD - NEGATIVE
        // EVEN - POSITIVE
        ok = false;
        bool pref = true;
        for (int i=0; i<n-2; i++) {
            if (i > 1)
                pref &= (i % 2 == 0 ? pSum[i-2] <= a[i-1] : pSum[i-2] >= -a[i-1]);
            long long old = pSum[i], bold = pSum[i+1];
            if (i % 2) {
                pSum[i] += a[i] - a[i+1];
                pSum[i+1] += 2LL * (a[i] - a[i+1]);
            } else {
                pSum[i] -= a[i] - a[i+1];
                pSum[i+1] -= 2LL * (a[i] - a[i+1]);
            }
            vector<long long> o1 = sMx[i+1], o2 = sMn[i+1], o3, o4;
            if (i + 2 < n) {
                o3 = sMx[i+2];
                o4 = sMn[i+2];
            }
            if (i == 0) DEBUG(sMn[i+1][0], sMn[i+2][0], 2LL * (a[i] - a[i+1]), pSum[i+1])
            bool cur = pref;
            for (int j=0; j<2; j++) {
                if (i % 2) {
                    if (i + 2 < n) {
                        sMx[i+2][j] += 2LL * (a[i] - a[i+1]);
                        sMn[i+2][j] += 2LL * (a[i] - a[i+1]);
                    }
                    sMx[i+1][j] = max((i + 1) % 2 == j ? pSum[i+1] : LLONG_MIN, i + 2 < n ? sMx[i+2][j] : LLONG_MIN);
                    sMn[i+1][j] = min((i + 1) % 2 == j ? pSum[i+1] : LLONG_MAX, i + 2 < n ? sMn[i+2][j] : LLONG_MAX);
                } else {
                    if (i + 2 < n) {
                        sMx[i+2][j] -= 2LL * (a[i] - a[i+1]);
                        sMn[i+2][j] -= 2LL * (a[i] - a[i+1]);
                    }
                    sMx[i+1][j] = max((i + 1) % 2 == j ? pSum[i+1] : LLONG_MIN, i + 2 < n ? sMx[i+2][j] : LLONG_MIN);
                    sMn[i+1][j] = min((i + 1) % 2 == j ? pSum[i+1] : LLONG_MAX, i + 2 < n ? sMn[i+2][j] : LLONG_MAX);
                }
            }
            swap(a[i], a[i+1]);
            if (i == 0) DEBUG(cur, check(i), check(i + 1), sMx[i+1][1], sMn[i+1][0], sMn[i+2][0])
            cur &= check(i) && check(i+1);
            if (cur) {
                ok = true;
                break;
            }
            pSum[i] = old;
            pSum[i+1] = bold;
            sMx[i+1] = o1;
            sMn[i+1] = o2;
            if (i + 2 < n) {
                sMx[i+2] = o3;
                sMn[i+2] = o4;
            }
            swap(a[i], a[i+1]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}