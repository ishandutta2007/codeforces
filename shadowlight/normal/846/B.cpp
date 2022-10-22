#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    ll n, k, m;
    cin >> n >> k >> m;
    vector <ll> t(k, 0);
    ll sum = 0;
    for (ll i = 0; i < k; i++) {
        cin >> t[i];
        sum += t[i];
    }
    sort(t.begin(), t.end());
    ll res = 0;
    for (ll i = 0; i <= n; i++) {
        ll tm = i * sum;
        if (tm > m) break;
        ll now = i * (k + 1);
        for (ll j = 0; j < k; j++) {
            if (tm + t[j] * (n - i) <= m) {
                tm += t[j] * (n - i);
                now += n - i;
                continue;
            }
            now += (m - tm) / t[j];
            break;
        }
        res = max(res, now);
    }
    cout << res;
}