#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

const int oo = 2e18 + 7;

inline int ff(int st, int en) {
    if (en < st) return 0;
    return st * (en - st + 1) + (en - st) * (en - st + 1) / 2;
}

inline int f(int x, int a, int b) {
    vector<pair<int, int>> v;
    v.pb({min(x, a), min(b, max(0LL, x - a))});
    v.pb({min(a, max(0LL, x - b)), min(x, b)});
    int ans = -oo;
    for (auto u : v) ans = max(ans, ff(a - u.x + 1, a) + ff(1, u.y));
    return ans;
}

const int N = 4e5 + 7;

int d[N], n, x;
int pr[N], pr2[N];

inline int get(int l, int r) {
    int a = l == 0 ? 0 : d[l - 1];
    int b = r == n - 1 ? 0 : d[r + 1];
    int xx = x - pr2[r + 1] + pr2[l];
    if (xx < 0) return -oo;
    return pr[r + 1] - pr[l] + f(xx, a, b);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) d[i + n] = d[i];
    n *= 2;
    for (int i = 0; i < n; i++) {
        pr[i + 1] = pr[i] + ff(1, d[i]);
        pr2[i + 1] = pr2[i] + d[i];
    }
    int pos = 0, ans = -oo;
    for (int i = 0; i < n; i++) {
        while (pos + 1 < n && (pos < i || pr2[pos + 2] - pr2[i] <= x)) pos++;
        for (int dl = -1; dl <= 1; dl++) {
            for (int dr = -1; dr <= 1; dr++) {
                if (i - dl >= 0 && pos + dr < n && i - dl <= pos + dr + 1) ans = max(ans, get(i - dl, pos + dr));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}