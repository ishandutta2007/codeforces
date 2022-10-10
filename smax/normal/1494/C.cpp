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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> pa, na, pb, nb;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            if (a > 0) pa.push_back(a);
            else na.push_back(-a);
        }
        for (int i=0; i<m; i++) {
            int b;
            cin >> b;
            if (b > 0) pb.push_back(b);
            else nb.push_back(-b);
        }
        DEBUG(pa, pb, na, nb);

        auto solve = [] (const vector<int> &a, const vector<int> &b) -> int {
            int n = (int) a.size(), m = (int) b.size();
            vector<int> suff(n + 1);
            for (int i=n-1; i>=0; i--)
                suff[i] = suff[i+1] + binary_search(b.begin(), b.end(), a[i]);
            int ret = suff[0], longest = 0, match = 0, j = 0, k = 0;
            vector<int> leave(m, INT_MAX);
            while (!a.empty() && j < m && b[j] < a[0])
                j++, k++;
            int delta = 0;
            for (int i=0; i<n; i++) {
                // if (j > 0 && b[j-1] + 1 == a[i])
                //     latest = min(latest, i);
                // else
                //     latest = 0;
                // longest = latest;
                delta++;
                while (j < m && (i == n - 1 || b[j] < a[i+1])) {
                    // move right of line to b[j]
                    leave[j] = b[j] + i + 1 - delta;
                    match++;
                    while (k < m && b[j] >= leave[k] + delta) {
                        k++;
                        match--;
                    }
                    longest = max(longest, match);
                    // if (j == 0 || b[j] == b[j-1] + 1) {
                    //     latest++;
                    // } else {
                    //     longest = max(longest, latest);
                    //     latest = 1;
                    // }
                    DEBUG(a, b, i, j, k, k > 0 ? leave[k-1] : -1, match);
                    j++;
                }
                // longest = max(longest, latest);
                // DEBUG(i, j, longest, latest, suff[i+1], a, min(longest, i + 1) + suff[i+1]);
                ret = max(ret, min(longest, i + 1) + suff[i+1]);
            }
            return ret;
        };

        reverse(na.begin(), na.end());
        reverse(nb.begin(), nb.end());
        cout << solve(pa, pb) + solve(na, nb) << "\n";
    }

    return 0;
}