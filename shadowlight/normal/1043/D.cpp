#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF1 = 1e9 + 7;
const ll INF2 = 1e9 + 5;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = MAXN;

ll get(ll l, ll r, vector <ll> &h, vector <ll> &p, ll P) {
    if (!l) {
        return h[r];
    }
    return (h[r] - h[l - 1] * p[r - l + 1] % P + P) % P;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    vector <vector <ll> > a(m, vector <ll> (n, 0));
    vector <vector <ll> > h1(m, vector <ll> (n, 0));
    vector <vector <ll> > p1(m, vector <ll> (n, 0));
    vector <vector <ll> > pos(m, vector <ll> (n + 1, 0));
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
        h1[i][0] = a[i][0];
        p1[i][0] = 1;
        for (ll j = 1; j < n; j++) {
            h1[i][j] = (h1[i][j - 1] * Q + a[i][j]) % INF1;
            p1[i][j] = p1[i][j - 1] * Q % INF1;
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = 1, r = n + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            bool can = true;
            if (pos[0][i] + mid > n) {
                r = mid;
                continue;
            }
            ll ha = get(pos[0][i], pos[0][i] + mid - 1, h1[0], p1[0], INF1);
            //ll hb = get(pos[0][i], pos[0][i] + mid - 1, h2[0], p2[0], INF2);
            for (ll j = 1; j < m; j++) {
                if (pos[j][i] + mid > n) {
                    can = false;
                    break;
                }
                ll hc = get(pos[j][i], pos[j][i] + mid - 1, h1[j], p1[j], INF1);
                //ll hd = get(pos[j][i], pos[j][i] + mid - 1, h2[j], p2[j], INF2);
                if (hc != ha) {
                    can = false;
                    break;
                }
            }
            if (can) {
                l = mid;
            } else {
                r = mid;
            }
        }
        res += l;
    }
    cout << res;
}