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

    long long xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    for (int rep=0; rep<4; rep++) {
        if (xc == 0 && yc == 0) {
            if (xa == xb && ya == yb) {
                cout << "YES\n";
                return 0;
            }
        } else {
            if (((xb - xa) * xc + (yb - ya) * yc) % (xc * xc + yc * yc) == 0) {
                long long m = ((xb - xa) * xc + (yb - ya) * yc) / (xc * xc + yc * yc);
                if (xc == 0) {
                    if ((xb - xa - m * xc) % yc == 0) {
                        cout << "YES\n";
                        return 0;
                    }
                } else {
                    if ((yb - ya - m * yc) % xc == 0) {
                        cout << "YES\n";
                        return 0;
                    }
                }
            }
        }
        tie(xa, ya) = make_pair(-ya, xa);
    }
    cout << "NO\n";

    return 0;
}