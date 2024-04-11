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

int n, hi[100000];
pair<int, int> mi[100000];

int query(int l, int r) {
    if (l <= r)
        return upper_bound(mi, mi + n, make_pair(r, INT_MAX)) - lower_bound(mi, mi + n, make_pair(l, -1));
    return ((mi + n) - lower_bound(mi, mi + n, make_pair(l, -1))) + (upper_bound(mi, mi + n, make_pair(r, INT_MAX)) - mi);
}

bool between(int l, int r, int x) {
    if (l <= r)
        return l <= x && x <= r;
    return l <= x || x <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int h, m, k;
    cin >> n >> h >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> hi[i] >> mi[i].first;
        mi[i].second = i + 1;
    }

    if (k == 1) {
        cout << "0 0\n";
        return 0;
    }

    sort(mi, mi + n);
    int mn = INT_MAX, retT;
    for (int i=0; i<n; i++) {
        int t = mi[i].first - (mi[i].first >= m / 2 ? m / 2 : 0);
        int ll = ((t - k + 1) % m + m) % m, rr = ((t - 1) % m + m) % m;
        DEBUG(t, ll, rr)
        int cur = query(ll, rr);
        ll = ((t + m / 2 - k + 1) % m + m) % m, rr = ((t + m / 2 - 1) % m + m) % m;
        DEBUG(ll, rr)
        cur += query(ll, rr);
        if (cur < mn) {
            mn = cur;
            retT = t;
        }
    }

    cout << mn << " " << retT << "\n";
    int ll = ((retT - k + 1) % m + m) % m, rr = ((retT - 1) % m + m) % m;
    int ll2 = ((retT + m / 2 - k + 1) % m + m) % m, rr2 = ((retT + m / 2 - 1) % m + m) % m;
    for (int i=0; i<n; i++)
        if (between(ll, rr, mi[i].first) || between(ll2, rr2, mi[i].first))
            cout << mi[i].second << " ";
    cout << "\n";

    return 0;
}