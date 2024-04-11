#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 30000000000000000;

ll di(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<ll> x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    x.push_back(x0);
    y.push_back(y0);
    while(x.back() <= INF && y.back() <= INF) {
        x.push_back(ax * x.back() + bx);
        y.push_back(ay * y.back() + by);
    }
    x.pop_back();
    y.pop_back();
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    int m = x.size(), ans = 0;
    for(int fi = 0; fi < m; fi++) {
        for(int la = fi; la < m; la++) {
                for(ll mi = fi; mi <= la; mi++) {
                ll d1 = di(xs, ys, x[mi], y[mi]) + di(x[mi], y[mi], x[fi], y[fi]) + di(x[fi], y[fi], x[la], y[la]);
                ll d2 = di(xs, ys, x[la], y[la]) + di(x[mi], y[mi], x[la], y[la]) + di(x[la], y[la], x[fi], y[fi]);
                if(min(d1, d2) <= t)
                    ans = max(ans, la - fi + 1);
            }
        }
    }
    cout << ans << '\n';
}