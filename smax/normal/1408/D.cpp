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

int a[2005], b[2005], c[2005], d[2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i] >> b[i];
    for (int i=0; i<m; i++)
        cin >> c[i] >> d[i];

    vector<pair<int, int>> pts;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            pts.emplace_back(c[j] - a[i] + 1, d[j] - b[i] + 1);

    sort(pts.begin(), pts.end());
    int ret = INT_MAX, mx = 0;
    for (int i=(int)pts.size()-1; i>=0; i--) {
        ret = min(ret, max(pts[i].first, 0) + mx);
        mx = max(mx, pts[i].second);
    }
    ret = min(ret, mx);
    cout << ret << "\n";

    return 0;
}