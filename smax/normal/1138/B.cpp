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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string c, a;
    cin >> n >> c >> a;

    // assume everyone clown
    // choose n / 2 people to become acrobats
    // x - y is number of valid clowns - valid acrobats
    // want x - y = 0
    // pick 0, 0: -0
    // pick 1, 0: -1
    // pick 0, 1: -1
    // pick 1, 1: -2
    int zero = 0, one = 0, two = 0, clowns = 0;
    for (int i=0; i<n; i++) {
        if (c[i] != a[i]) one++;
        else if (c[i] == '0') zero++;
        else two++;
        clowns += c[i] == '1';
    }
    DEBUG(clowns);

    for (int x=0; x<=one; x++)
        if ((clowns - x) % 2 == 0) {
            int y = (clowns - x) / 2, z = max(n / 2 - x - y, 0);
            DEBUG(x, y, z);
            if (y >= 0 && y <= two && z <= zero && x + y + z == n / 2) {
                set<int> st;
                for (int i=0; i<n; i++) {
                    if (c[i] != a[i] && x > 0) {
                        st.insert(i);
                        x--;
                    } else if (c[i] == '0' && a[i] == '0' && z > 0) {
                        st.insert(i);
                        z--;
                    } else if (c[i] == '1' && a[i] == '1' && y > 0) {
                        st.insert(i);
                        y--;
                    }
                }
                for (int i=0; i<n; i++)
                    if (!st.count(i))
                        cout << i + 1 << " ";
                cout << "\n";
                return 0;
            }
        }
    cout << "-1\n";

    return 0;
}