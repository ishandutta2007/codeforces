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
    int last = -1, cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        int b = 31 - __builtin_clz(a[i]);
        if (b == last) cnt++;
        else last = b, cnt = 1;
        if (cnt > 2) {
            cout << "1\n";
            return 0;
        }
    }

    int ret = INT_MAX;
    // [i, j] [j + 1, k]
    for (int i=0; i<n; i++) {
        int l = 0;
        for (int j=i; j<n; j++) {
            l ^= a[j];
            int r = 0;
            for (int k=j+1; k<n; k++) {
                r ^= a[k];
                if (l > r)
                    ret = min(ret, k - i - 1);
            }
        }
    }
    cout << (ret == INT_MAX ? -1 : ret) << "\n";

    return 0;
}