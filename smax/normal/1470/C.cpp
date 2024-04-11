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

int ask(int q) {
    cout << "? " << q + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int SZ = sqrt(n) - 1;

    for (int i=0; i<SZ; i++)
        ask(0);

    int pos = -1;
    for (int i=0; i<n; i+=SZ)
        if (ask(i) > k) {
            pos = i;
            break;
        }
    assert(pos != -1);

    // rotate the circle so that pos is at n - 1
    int l = 0, r = n, offset = n - 1 - pos;
    while (l < r) {
        int m = (l + r) / 2;
        if (ask((m + n - offset) % n) > k)
            r = m;
        else
            l = m + 1;
    }
    cout << "! " << (l - 1 + n - offset) % n + 1 << endl;

    return 0;
}