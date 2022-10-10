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

int a[300000], ptr[10];
long long pref[300000], add[10];
vector<pair<long long, int>> mx[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pref[i] = (i > 0 ? pref[i-1] : 0) + a[i];
        if (i % m == 0)
            pref[i] -= k;
        mx[i % m].emplace_back(pref[i], i);
    }
    for (int i=0; i<m; i++)
        if (!mx[i].empty())
            sort(mx[i].rbegin(), mx[i].rend());

    long long ret = 0, rem = 0;
    for (int i=0; i<m; i++)
        if (!mx[i].empty())
            ret = max(ret, mx[i][0].first);
    for (int i=1; i<n; i++) {
        rem += a[i-1];
        add[(i - 1) % m] += k;
        for (int j=0; j<m; j++) {
            while (ptr[j] < mx[j].size() && mx[j][ptr[j]].second < i)
                ptr[j]++;
            if (ptr[j] < mx[j].size())
                ret = max(ret, mx[j][ptr[j]].first + add[j] - rem);
        }
    }

    cout << ret << "\n";

    return 0;
}