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
        vector<long long> x(4), y(4);
        for (int i=0; i<4; i++)
            cin >> x[i] >> y[i];

        // top left, bottom left, top right, bottom right
        vector<int> perm{0, 1, 2, 3};

        auto f = [&] (long long k) {
            vector<long long> cx(4), cy(4);
            for (int i=0; i<4; i++) {
                cx[i] = x[perm[i]];
                cy[i] = y[perm[i]];
                if (i >= 2) cx[i] -= k;
                if (i == 0 || i == 2) cy[i] -= k;
            }
            sort(cx.begin(), cx.end());
            sort(cy.begin(), cy.end());
            long long ret = 0;
            for (int i=0; i<4; i++)
                ret += abs(cx[i] - cx[2]) + abs(cy[i] - cy[2]);
            return ret;
        };

        long long ret = LLONG_MAX;
        do {
            // say side length = k, left x-coordinate = x
            // minimize abs(x0 - x) + abs(x2 - (x + k)) + ...
            // = abs(x0 - x) + abs(x2 - k - x) + ...
            // median is optimal
            // ternary search works in this instance because equal values only occur at extrema
            long long l = 0, r = 1e9 + 5;
            while (l < r) {
                long long m = (l + r) / 2;
                if (f(m) > f(m + 1))
                    l = m + 1;
                else
                    r = m;
            }
            ret = min(ret, f(l));
        } while (next_permutation(perm.begin(), perm.end()));
        cout << ret << "\n";
    }

    return 0;
}