#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <char> num = {'U', 'L', 'R', 'D'};
vector <ll> dx = {0, -1, 1, 0};
vector <ll> dy = {1, 0, 0, -1};

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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    ll d = ((x + y) % 2 + 2) % 2;
    if (d != n % 2) {
        cout << -1;
        return 0;
    }
    vector <pair <ll, ll> > pref(n, {0, 0});
    vector <pair <ll, ll> > suf(n + 1, {0, 0});
    for (ll i = 0; i < n; i++) {
        if (i) {
            pref[i] = pref[i - 1];
        }
        for (ll d = 0; d < 4; d++) {
            if (s[i] == num[d]) {
                pref[i].first += dx[d];
                pref[i].second += dy[d];
            }
        }
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            suf[i] = suf[i + 1];
        }
        for (ll d = 0; d < 4; d++) {
            if (s[i] == num[d]) {
                suf[i].first += dx[d];
                suf[i].second += dy[d];
            }
        }
    }
    ll res = INF;
    for (ll i = 0; i <= n; i++) {
        ll xn = 0, yn = 0;
        if (i) {
            xn += pref[i - 1].first, yn += pref[i - 1].second;
        }
        if (n - i < abs(x - xn) + abs(y - yn)) continue;
        ll lt = -1, rt = n;
        while (rt - lt > 1) {
            ll mid = (lt + rt) / 2;
            if (i + mid > n) {
                rt = mid;
                continue;
            }
            ll xa = xn, ya = yn;
            xa += suf[i + mid].first, ya += suf[i + mid].second;
            if (mid >= abs(x - xa) + abs(y - ya)) {
                rt = mid;
            } else {
                lt = mid;
            }
        }
        //cout << i << " " << rt << "\n";
        res = min(res, rt);
    }
    cout << (res == INF ? -1 : res);
}