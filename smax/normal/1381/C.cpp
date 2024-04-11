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

#define MAXN 100005

int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> cnt(n + 1);
        vector<vector<int>> sorted(n + 1), color(n + 1);
        for (int i=0; i<n; i++) {
            cin >> b[i];
            cnt[--b[i]]++;
            color[b[i]].push_back(i);
            sorted[cnt[b[i]]].push_back(i);
        }

        int f = n;
        for (int i=0; i<x; i++) {
            while (sorted[f].empty())
                f--;
            a[sorted[f].back()] = b[sorted[f].back()];
            color[b[sorted[f].back()]].pop_back();
            sorted[f].pop_back();
        }
        while (f > 0 && sorted[f].empty())
            f--;
        if (2 * f > 2 * n - x - y) {
            cout << "NO\n";
            continue;
        }

        vector<int> all;
        for (int i=0; i<=n; i++)
            all.insert(all.end(), color[i].begin(), color[i].end());
        assert((int) all.size() == n - x);

        int change = n - y, odd = 0;
        while (cnt[odd])
            odd++;
        for (int i=0; i<n-x; i++) {
            a[all[i]] = b[all[(i + (n - x) / 2) % (n - x)]];
            if (a[all[i]] == b[all[i]]) {
                a[all[i]] = odd;
                change--;
            }
        }
        for (int i=0; change>0; i++)
            if (a[all[i]] != odd) {
                a[all[i]] = odd;
                change--;
            }

        cout << "YES\n";
        for (int i=0; i<n; i++)
            cout << a[i] + 1 << " \n"[i==n-1];
    }

    return 0;
}