#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e6 + 7;
const double EPS = 1e-8;

vector <ll> st, g, d, p;
ll n, k;

ll power(ll a, ll k) {
    if (!k) {
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

void init() {
    st.resize(MAXN, 0);
    g.resize(MAXN, 0);
    d.resize(MAXN, -1);
    for (int i = 0; i < MAXN; i++) {
        st[i] = power(i, n);
    }
    for (ll i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            d[i] = p.size();
            p.push_back(i);
        }
        for (ll j = 0; j <= d[i]; j++) {
            if (p[j] * i >= MAXN) break;
            d[p[j] * i] = j;
        }
    }
    g[1] = 1;
    for (ll i = 2; i < MAXN; i++) {
        ll cnt = 0, pr = -1;
        ll x = i;
        bool fl = false;
        while (x > 1) {
            if (pr == p[d[x]]) {
                fl = true;
                break;
            }
            cnt++;
            pr = p[d[x]];
            x /= p[d[x]];
        }
        if (!fl) {
            g[i] = (cnt % 2 ? -1 : 1);
        }
    }
}

ll sum = 0;

vector <ll> f(MAXN, 0);

void rec(ll pred, vector <pair <ll, ll> > &allp, ll x, ll now) {
    if (pred == allp.size()) {
        //cout << now << " ";
        sum += INF - f[now] * g[now];
        f[now] = st[x / now];
        sum += f[now] * g[now];
        while (sum >= INF) {
            sum -= INF;
        }
        return;
    }
    for (ll i = 0; i <= allp[pred].second; i++) {
        rec(pred + 1, allp, x, now);
        now *= allp[pred].first;
    }
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
    cin >> n >> k;
    init();
    ll res = 0;
    for (ll i = 1; i <= k; i++) {
        vector <pair <ll, ll> > allp;
        ll pr = -1;
        ll x = i;
        while (x > 1) {
            if (p[d[x]] == pr) {
                allp.back().second++;
            } else {
                allp.push_back({p[d[x]], 1});
                pr = p[d[x]];
            }
            x /= p[d[x]];
        }
        //cout << i << ":\n";
        rec(0, allp, i, 1);
        //cout << "\n";
        res += sum ^ i;
        res %= INF;
    }
    cout << res << "\n";
}