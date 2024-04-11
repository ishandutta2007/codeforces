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

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long w;
        cin >> n >> w;
        vector<pair<int, int>> a(n);
        int idx = -1;
        bool ok = false;
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            if (a[i].first * 2 >= w && a[i].first <= w)
                idx = i;
            if (a[i].first <= w)
                ok = true;
        }
        if (idx != -1) {
            cout << "1 " << idx + 1 << "\n";
            continue;
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        sort(a.begin(), a.end());
        int i = 0;
        vector<int> ret;
        long long sum = 0;
        while (i < n && sum * 2 < w) {
            ret.push_back(a[i].second);
            sum += a[i++].first;
        }
        if (sum * 2 < w || sum > w) {
            cout << "-1\n";
            continue;
        }
        DEBUG(sum, ret, a)
        assert(sum * 2 >= w && sum <= w);
        cout << ret.size() << "\n";
        for (int x : ret)
            cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}