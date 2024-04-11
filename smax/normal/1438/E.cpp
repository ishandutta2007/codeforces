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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    long long ret = 0;
    for (int rep=0; rep<2; rep++) {
        for (int i=0; i<n; i++) {
            int k = 31 - __builtin_clz(a[i]);
            long long sum = 0;
            for (int j=i+1; j<n && sum<1LL<<(k+1); j++) {
                if (j - i > 1 && (a[i] ^ a[j]) == sum && !(rep == 1 && a[j] & (1 << k)))
                    ret++;
                sum += a[j];
            }
        }
        reverse(a.begin(), a.end());
    }
    cout << ret << "\n";

    return 0;
}