#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const int N = (int)1e6 + 50;

struct P {
    ll x, y, a;
} p[N];


int n;
ll dp[N];
deque<int> que;

bool smaller(pll x, pll y) {
    ll xa = x.first, xb = x.second, remx = xa % xb;
    ll ya = y.first, yb = y.second, remy = ya % yb;
    if((xa - remx) / xb != (ya - remy) / yb) return (xa - remx) / xb < (ya - remy) / yb;
    else return remx * yb <= remy * xb;
}

pll slp(int i, int j) {
    return {dp[j] - dp[i], p[j].x - p[i].x};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> p[i].a;
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.y > p2.y;
    });
    for(int i = 0; i < n; i++) {
        dp[i] = p[i].x * p[i].y - p[i].a;
        while(que.size() > 1) {
            if(smaller({p[i].y, 1}, slp(que[0], que[1]))) que.pop_front();
            else break;
        }
        if(!que.empty()) {
            int j = que.front();
            dp[i] = max(dp[i], dp[j] + p[i].y * (p[i].x - p[j].x) - p[i].a);
        }
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(smaller(slp(que[ls-1], que[ls]), slp(que[ls], i))) que.pop_back();
            else break;
        }
        que.push_back(i);
    }
    ll res = 0;
    for(int i = 0; i < n; i++) res = max(res, dp[i]);
    cout << res << endl;
}