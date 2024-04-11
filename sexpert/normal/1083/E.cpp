#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 5;
ll dp[MAXN];

struct line {
    ll m, b;
    ll eval(ll x) { return m*x + b; }
    ll div(ll a, ll b) {return a/b - ((a ^ b) < 0 && a % b);}
    ll isect(const line &o) { return div(o.b - b, m - o.m); }
};
deque<line> dq;

ll query(ll x) {
    while(dq.size() >= 2 && dq.back().eval(x) <= dq[dq.size() - 2].eval(x))
        dq.pop_back();
    return dq.back().eval(x);
}

void add(ll m, ll b) {
    line l = line{m, b};
    while(dq.size() >= 2 && l.isect(dq[0]) >= dq[0].isect(dq[1]))
        dq.pop_front();
    dq.push_front(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pll, ll>> rect(n);
    for(int i = 0; i < n; i++) {
        ll x, y, a;
        cin >> x >> y >> a;
        rect[i] = make_pair(pll{x, y}, a);
    }
    sort(rect.begin(), rect.end());
    dp[0] = 0;
    add(0, 0);
    for(int i = 0; i < n; i++) {
        ll ans = rect[i].first.first * rect[i].first.second - rect[i].second;
        ans += query(rect[i].first.second);
        dp[i + 1] = ans;
        add(-rect[i].first.first, dp[i + 1]);
    }
    ll mx = 0;
    for(int i = 1; i <= n; i++)
        mx = max(mx, dp[i]);
    cout << mx << endl;
}