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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long pos = -INF, neg = INF;
        int posCnt = 0, negCnt = 0;
        bool ok = true, zero = false;
        for (long long &x : a) {
            cin >> x;
            if (x > 0) {
                if (pos == -INF)
                    pos = x;
                else
                    ok = false;
                posCnt++;
            } else if (x < 0) {
                if (neg == INF)
                    neg = x;
                else
                    ok = false;
                negCnt++;
            } else {
                zero = true;
            }
        }
        if (zero) {
            ok &= pos == -INF || neg == INF || pos == -neg;
        } else if (posCnt >= 3 || negCnt >= 3) {
            ok = false;
        } else {
            assert(n < 6);
            ok = true;
            for (int i=0; i<n; i++)
                for (int j=i+1; j<n; j++)
                    for (int k=j+1; k<n; k++)
                        ok &= find(a.begin(), a.end(), a[i] + a[j] + a[k]) != a.end();
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}