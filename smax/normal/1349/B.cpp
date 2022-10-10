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

int a[100000], b[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b + n);
        if (b[(n-1)/2] == k) {
            cout << "yes\n";
            continue;
        }
        bool ok = false;
        for (int i=0; i<(n-1)/2; i++)
            if (b[i] == k) {
                ok = true;
                break;
            }
        bool bigger = false;
        for (int i=(n-1)/2+1; i<n; i++)
            if (b[i] == k) {
                bigger = true;
                break;
            }

        if (bigger) {
            int pred = -1;
            bool enough = false;
            for (int i=0; i<n; i++)
                if (a[i] >= k) {
                    if (pred != -1 && i - pred <= 2) {
                        enough = true;
                        break;
                    }
                    pred = i;
                }
            ok |= enough;
        }

        cout << (ok ? "yes" : "no") << "\n";
    }

    return 0;
}