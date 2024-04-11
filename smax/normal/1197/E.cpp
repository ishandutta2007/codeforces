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

const int MOD = 1e9 + 7;

int suff[200000], tot[200000];
pair<int, int> a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i].second >> a[i].first;

    sort(a, a + n);
    memset(suff, 127, sizeof(suff));
    for (int i=n-1; i>=0; i--) {
        int minSpace = a[i].first, cnt = 1, j = lower_bound(a, a + n, make_pair(a[i].second, -1)) - a;
        if (j < n) {
            minSpace = suff[j] - a[i].second + a[i].first;
            cnt = tot[j];
        }
        if (i < n - 1 && minSpace >= suff[i+1]) {
            suff[i] = suff[i+1];
            tot[i] = tot[i+1];
        }
        if (minSpace <= suff[i]) {
            suff[i] = min(suff[i], minSpace);
            tot[i] += cnt;
            if (tot[i] >= MOD) tot[i] -= MOD;
        }
    }

    cout << tot[0] << "\n";

    return 0;
}