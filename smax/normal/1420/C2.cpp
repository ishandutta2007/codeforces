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

int a[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        a[0] = a[n+1] = 0;

        long long tot = 0;
        vector<bool> add(n + 1), sub(n + 1);
        for (int i=0; i<=n; i++) {
            int s = i++;
            while (i <= n && a[i] >= a[i-1])
                i++;
            tot += a[--i] - a[s];
            if (s != i)
                sub[s] = add[i] = true;
        }
        cout << tot << "\n";

        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l != r) {
                swap(a[l], a[r]);
                swap(add[l], add[r]);
                swap(sub[l], sub[r]);
                for (int i : {l - 1, l, l + 1, r - 1, r, r + 1}) {
                    if (i < 1 || i > n)
                        continue;
                    // peak
                    if (a[i] > a[i-1] && a[i] > a[i+1]) {
                        if (!add[i]) {
                            add[i] = true;
                            tot += a[i];
                        }
                    } else {
                        if (add[i]) {
                            add[i] = false;
                            tot -= a[i];
                        }
                    }
                    // trough
                    if (a[i] < a[i-1] && a[i] < a[i+1]) {
                        if (!sub[i]) {
                            sub[i] = true;
                            tot -= a[i];
                        }
                    } else {
                        if (sub[i]) {
                            sub[i] = false;
                            tot += a[i];
                        }
                    }
                }
            }
            cout << tot << "\n";
        }
    }

    return 0;
}