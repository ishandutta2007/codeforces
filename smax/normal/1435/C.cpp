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

    vector<int> a(6);
    for (int i=0; i<6; i++)
        cin >> a[i];
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i=0; i<n; i++)
        cin >> b[i];

    vector<pair<int, int>> diff;
    for (int i=0; i<n; i++)
        for (int j=0; j<6; j++)
            diff.emplace_back(b[i] - a[j], i);

    sort(diff.begin(), diff.end());
    int ret = INT_MAX, has = 0;
    vector<int> cnt(n);
    for (int i=0, j=0; i<6*n; i++) {
        if (i > 0 && --cnt[diff[i-1].second] == 0)
            has--;
        while (has < n && j < 6 * n) {
            if (++cnt[diff[j].second] == 1)
                has++;
            j++;
        }
        if (has == n)
            ret = min(ret, diff[j-1].first - diff[i].first);
    }
    cout << ret << "\n";

    return 0;
}