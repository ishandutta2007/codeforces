#include <bits/stdc++.h>
using namespace std;

#define N 10005

typedef long long ll;
typedef pair<ll, ll> pll;

int n, m, tot;
pll a[N];
priority_queue<pll> pq;
priority_queue<ll> pql;
ll ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%I64d", &a[i].first);
        a[i].second = -1;
        tot --;
    }
    for (int i = 0; i < m; i ++) {
        scanf("%I64d %I64d", &a[n].first, &a[n].second);
        tot += a[n++].second;
    }
    if (tot < 0) return puts("-1"), 0;
    sort(a, a + n);
    pq.push(pll(-1e12, 1e5));
    for (int i = 0; i < n; i ++) {
        pll now = a[i];
        if (~now.second) {
            ll t;
            for (; now.second && !pql.empty() && (t = pql.top()) > now.first; now.second --) {
                ll c = t - now.first;
                ans -= c;
                pql.pop();
                pq.push(pll(now.first - c, 1));
            }
            if (now.second) pq.push(now);
        }
        else {
            pll tmp = pq.top(); pq.pop();
            if (--tmp.second) pq.push(tmp);
            ll c = now.first - tmp.first;
            ans += c;
            pql.push(now.first + c);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}