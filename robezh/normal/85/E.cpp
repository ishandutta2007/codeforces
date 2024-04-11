#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 5005, INF = (int)1e9, mod = (int)1e9 + 7;
int n;
int x[N], y[N];

bool in_bound(int x, int y, int lx, int rx, int ly, int ry) {
    return lx <= x && x <= rx && ly <= y && y <= ry;
}

ll pw2[N];

ll solve(int len) {
    int mx_x = -INF, mn_x = INF, mx_y = -INF, mn_y = INF;
    ll res = 0;
    rep(i, 0, n) {
        mx_x = max(mx_x, x[i]);
        mn_x = min(mn_x, x[i]);
        mx_y = max(mx_y, y[i]);
        mn_y = min(mn_y, y[i]);
    }
    if(mx_x - mn_x <= len && mx_y - mn_y <= len) return pw2[n];

    bool good = false;
    bool good0 = true;
    int cnt0 = 0;
    rep(i, 0, n) {
        if (!in_bound(x[i], y[i], mn_x, mn_x + len, mn_y, mn_y + len) &&
            !in_bound(x[i], y[i], mx_x - len, mx_x, mx_y - len, mx_y)) {
            good0 = false;
            break;
        }
        cnt0 += in_bound(x[i], y[i], mn_x, mn_x + len, mn_y, mn_y + len) &&
                in_bound(x[i], y[i], mx_x - len, mx_x, mx_y - len, mx_y);
    }

    if(good0) {
        good = true;
        res = pw2[cnt0] * 2 % mod;
    }

    if(mx_x - mn_x > len && mx_y - mn_y > len) {
        bool good1 = true;
        int cnt1 = 0;
        rep(i, 0, n) {
            if (!in_bound(x[i], y[i], mn_x, mn_x + len, mx_y - len, mx_y) &&
                !in_bound(x[i], y[i], mx_x - len, mx_x, mn_y, mn_y + len)) {
                good1 = false;
                break;
            }
            cnt1 += in_bound(x[i], y[i], mn_x, mn_x + len, mx_y - len, mx_y)&&
                   in_bound(x[i], y[i], mx_x - len, mx_x, mn_y, mn_y + len);
        }
        if(good1) {
            good = true;
            res = (res + pw2[cnt1] * 2) % mod;
        }
    }

    return good ? res : -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    rep(i, 1, N) pw2[i] = pw2[i - 1] * 2 % mod;
    cin >> n;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        tie(x[i], y[i]) = pii{x[i] + y[i], x[i] - y[i]};
    }
    int l = -1, r = 10005, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(solve(mid) >= 0) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    cout << solve(r) << '\n';

}