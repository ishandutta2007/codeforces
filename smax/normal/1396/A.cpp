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

long long inverse(long long a, int mod) {
    long long m = mod, x = 1, y = 0;
    while (a > 1) {
        long long q = a / m, t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += mod;
    return x;
}

long long a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    long long inv = inverse(n, n - 1);
    cout << "1 " << n << "\n";
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (n == 1) {
            cout << -a[i] << " ";
            a[i] = 0;
        } else {
            long long r = a[i] % (n - 1);
            if (r == 0) {
                cout << "0 ";
            } else {
                long long k = (n - 1 - r) * inv % (n - 1);
                cout << n * k << " ";
                a[i] += n * k;
            }
        }
    }
    cout << "\n";

    if (n == 1) {
        cout << "1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout << "1 " << n - 1 << "\n";
    for (int i=0; i<n-1; i++)
        cout << -a[i] << " ";
    cout << "\n" << n << " " << n << "\n" << -a[n-1] << "\n";

    return 0;
}