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

    int n4, n7, n47, n74;
    cin >> n4 >> n7 >> n47 >> n74;

    if (abs(n47 - n74) > 1 || (n47 == n74 && (min(n4, n7) < n47 || max(n4, n7) <= n47)) || (n47 != n74 && min(n4, n7) < max(n47, n74))) {
        cout << "-1\n";
        return 0;
    }

    if (n47 == n74) {
        if (n4 == n47) {
            cout << '7';
            n7--;
            for (int i=0; i<n47; i++) {
                cout << "47";
                n7--;
            }
            for (int i=0; i<n7; i++)
                cout << '7';
            cout << "\n";
        } else {
            for (int i=0; i<n4-n74; i++)
                cout << '4';
            for (int i=0; i<n74-1; i++) {
                cout << "74";
                n7--;
            }
            for (int i=0; i<n7; i++)
                cout << '7';
            cout << "4\n";
        }
    } else if (n47 < n74) {
        cout << '7';
        n7--;
        n74--;
        for (int i=0; i<n4-n74; i++)
            cout << '4';
        for (int i=0; i<n74-1; i++) {
            cout << "74";
            n7--;
        }
        for (int i=0; i<n7; i++)
            cout << '7';
        cout << "4\n";
    } else {
        for (int i=0; i<n4-n47; i++)
            cout << '4';
        for (int i=0; i<n47; i++) {
            cout << "47";
            n7--;
        }
        for (int i=0; i<n7; i++)
            cout << '7';
        cout << "\n";
    }

    return 0;
}