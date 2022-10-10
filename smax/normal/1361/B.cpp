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

const int MOD = 1e9 + 7;

int power(long long a, int b) {
    long long ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

int k[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        for (int i=0; i<n; i++)
            cin >> k[i];

        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }

        sort(k, k + n);
        long long ret = power(p, k[n-1]), can = 1;
        bool infinity = false;
        for (int i=n-2; i>=0; i--) {
            if (infinity) {
                ret -= power(p, k[i]);
                if (ret < 0)
                    ret += MOD;
            } else if (can == 0) {
                ret += power(p, k[i]);
                if (ret >= MOD)
                    ret -= MOD;
                can = 1;
            } else {
                int d = k[i+1] - k[i];
                for (int j=0; j<d; j++) {
                    can *= p;
                    if (can > n) {
                        infinity = true;
                        break;
                    }
                }
                ret -= power(p, k[i]);
                if (ret < 0)
                    ret += MOD;
                can--;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}