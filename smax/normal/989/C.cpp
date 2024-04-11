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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--;

    cout << "33 50\n";
    for (int i=0; i<4; i++) {
        for (int j=0; j<25; j++) {
            if (b-- > 0) cout << 'B';
            else cout << 'A';
            cout << 'A';
        }
        cout << "\n";
        for (int j=0; j<50; j++)
            cout << 'A';
        cout << "\n";
    }
    for (int i=0; i<50; i++)
        cout << 'B';
    cout << "\n";
    for (int i=0; i<4; i++) {
        for (int j=0; j<25; j++) {
            if (a-- > 0) cout << 'A';
            else cout << 'B';
            cout << 'B';
        }
        cout << "\n";
        for (int j=0; j<50; j++)
            cout << 'B';
        cout << "\n";
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<25; j++) {
            if (c-- > 0) cout << 'C';
            else cout << 'B';
            cout << 'B';
        }
        cout << "\n";
        for (int j=0; j<50; j++)
            cout << 'B';
        cout << "\n";
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<25; j++) {
            if (d-- > 0) cout << 'D';
            else cout << 'B';
            cout << 'B';
        }
        cout << "\n";
        for (int j=0; j<50; j++)
            cout << 'B';
        cout << "\n";
    }

    return 0;
}