#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (k <= 0) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
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
    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll cnt = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (!a[i]) {
            cnt++;
        }
        if (!b[i]) {
            cnt++;
        }
    }
    ll bot = cnt;
    vector <ll> st(cnt + 5, 0);
    for (ll i = 0; i < n; i++) {
        if (a[i] && b[i]) {
            if (a[i] < b[i]) {
                break;
            } else if (a[i] > b[i]) {
                st[cnt]++;
                break;
            }
            continue;
        }
        if (!a[i] && !b[i]) {
            cnt -= 2;
            st[cnt] += m * (m - 1) / 2;
            cnt++;
        } else if (!a[i]) {
            cnt--;
            st[cnt] += m - b[i];
        } else {
            cnt--;
            st[cnt] += a[i] - 1;
        }
    }
    bool fl = false;
    ll x = 1;
    ll top = 0;
    ll add = 0;
    for (ll i = 0; i < (int) st.size(); i++) {
        if (st[i] >= m) {
            st[i + 1] += st[i] / m;
            st[i] %= m;
        }
        if (!fl) {
            if (!st[i]) {
                add++;
                continue;
            }
            fl = true;
            x = __gcd(st[i], m);
            top += (st[i] / x) * power(m, i - add) % INF;
            top %= INF;
        } else {
            top += st[i] * power(m, i - 1 - add) % INF * (m / x) % INF;
            top %= INF;
        }
    }
    if (bot - 1 - add < 0) {
        bot = 1;
    } else {
        bot = power(m, bot - 1 - add) * (m / x) % INF;
    }
    //cout << top << " " << bot << "\n";
    cout << top * rev(bot) % INF;
}