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

        if (n % 2 || n == 2) {
            cout << (n > 1 ? "Ashishgup" : "FastestFinger") << "\n";
            continue;
        }

        int cnt = 0, two = 0;
        for (int i=2; i*i<=n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                    if (i != 2) cnt++;
                    else two++;
                }
            }
        }
        if (n > 1 && n != 2)
            cnt++;

        if (cnt > 0) {
            if (two == 1)
                cout << (cnt > 1 ? "Ashishgup" : "FastestFinger") << "\n";
            else
                cout << "Ashishgup\n";
        } else {
            cout << "FastestFinger\n";
        }
//        cout << (cnt > 0 && two != 1 ? "Ashishgup" : "FastestFinger") << "\n";
    }

    return 0;
}