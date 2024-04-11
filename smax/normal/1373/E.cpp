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
        int n, k;
        cin >> n >> k;

        long long ret = LLONG_MAX;
        for (int i=0; i<10; i++) {
            // end in i
            if (i <= 9 - k) {
                int add = k * (k + 1) / 2;
                if (n - add >= 0 && (n - add) % (k + 1) == 0 && (n - add) / (k + 1) >= i) {
                    int sum = (n - add) / (k + 1);
                    long long cur = 0, power = 1;
                    while (sum > 0) {
                        int d = (power == 1 ? i : min(sum, 9));
                        cur += power * d;
                        sum -= d;
                        power *= 10;
                    }
                    ret = min(ret, cur);
                }
            } else {
                for (int j=0; j<18; j++) {
                    // has j 9's
                    long long power = 10;
                    for (int l=0; l<j; l++)
                        power *= 10;
                    long long quant = n - (10 - i) * (i + j * 9) - (9 - i) * (10 - i) / 2 - (i + k - 9) - (i + k - 9) * (i + k - 10) / 2;
                    if (quant >= 0 && quant % (k + 1) == 0) {
                        int sum = quant / (k + 1);
                        long long cur = 0, orig = power;
                        while (sum > 0) {
                            int d = min(sum, power == orig ? 8 : 9);
                            cur += power * d;
                            sum -= d;
                            power *= 10;
                        }
                        ret = min(ret, cur + orig - 10 + i);
                    }
                }
            }
        }

        cout << (ret == LLONG_MAX ? -1 : ret) << "\n";
    }

    return 0;
}