#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

struct Ticket {
    ll d, f, t, c;
};

bool operator<(Ticket a, Ticket b) {
    return a.d < b.d;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, m, k;
    cin >> n >> m >> k;
    vector <Ticket> data(m);
    ll cnt = 0;
    for (ll i = 0; i < m; i++) {
        ll d, f, t, c;
        cin >> d >> f >> t >> c;
        data[i] = {d, t, f, c};
    }
    sort(data.begin(), data.end());
    vector <multiset <ll> > cost(n + 1);
    for (auto p : data) {
        if (!p.f) {
            continue;
        }
        cost[p.f].insert(p.c);
    }
    ll now = 0;
    vector <ll> minc(n + 1, INF);
    ll sum1 = 0, sum2 = 0;
    ll ans = INF;
    for (ll i = 1; i <= n; i++) {
        if (cost[i].empty()) {
            cout << -1;
            return 0;
        }
        sum2 += *cost[i].begin();
    }
    for (auto p : data) {
        if (p.f) continue;
        if (minc[p.t] == INF) {
            cnt++;
        } else {
            sum1 -= minc[p.t];
        }
        minc[p.t] = min(minc[p.t], p.c);
        sum1 += minc[p.t];
        ll tm = p.d + k;
        while (now < m && data[now].d <= tm) {
            auto p1 = data[now];
            now++;
            if (!p1.f) continue;
            sum2 -= *cost[p1.f].begin();
            cost[p1.f].erase(cost[p1.f].find(p1.c));
            if (cost[p1.f].empty()) {
                sum2 = INF;
            } else {
                sum2 += *cost[p1.f].begin();
            }
        }
        //cout << p.d << " " << data[now].d << "\n";
        if (sum2 == INF) break;
        //cout << cnt << " " << sum1 << " " << sum2 << "\n";
        if (cnt == n) {
            ans = min(ans, sum1 + sum2);
        }
    }
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}