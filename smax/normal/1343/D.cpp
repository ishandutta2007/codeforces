#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int a[200000], cnt[400001];

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
        for (int i=0; i<n; i++)
            cin >> a[i];

        memset(cnt, 0, sizeof(int) * (2 * k + 1));
        ordered_set mx, mn;
        for (int i=0; i<n/2; i++) {
            cnt[a[i] + a[n-i-1]]++;
            mx.insert({max(a[i], a[n-i-1]) + k, i});
            mn.insert({min(a[i], a[n-i-1]) + 1, i});
        }

        int ret = INT_MAX;
        for (int x=2; x<=2*k; x++) {
            int num = mx.order_of_key(make_pair(x, -1)) + n / 2 - mn.order_of_key(make_pair(x + 1, -1));
            ret = min(ret, 2 * num + (n / 2 - num - cnt[x]));
        }

        cout << ret << "\n";
    }

    return 0;
}