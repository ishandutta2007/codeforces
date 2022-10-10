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

long long a[100005], diff[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i > 0) {
            diff[i-1] = a[i] - a[i-1];
            sum += max(diff[i-1], 0LL);
        }
    }
    DEBUG(sum, a[0])
    cout << (sum + a[0] + (sum + a[0] > 0)) / 2 << "\n";

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l > 0) {
            sum -= max(diff[l-1], 0LL);
            diff[l-1] += x;
            sum += max(diff[l-1], 0LL);
        } else {
            a[0] += x;
        }
        if (r + 1 < n) {
            sum -= max(diff[r], 0LL);
            diff[r] -= x;
            sum += max(diff[r], 0LL);
        }
        cout << (sum + a[0] + (sum + a[0] > 0)) / 2 << "\n";
    }

    return 0;
}