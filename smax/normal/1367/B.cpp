#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int a[40];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] %= 2;
        }

        int ret = 0;
        for (int i=0; i<n; i++)
            if (i % 2 != a[i] % 2) {
                bool ok = false;
                for (int j=i+1; j<n; j++)
                    if (j % 2 != a[j] % 2 && i % 2 == a[j] % 2) {
                        ok = true;
                        ret++;
                        swap(a[i], a[j]);
                        break;
                    }
                if (!ok) {
                    ret = -1;
                    break;
                }
            }

        cout << ret << "\n";
    }

    return 0;
}