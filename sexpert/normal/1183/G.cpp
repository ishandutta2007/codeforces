#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

void solve() {
    int n;
    cin >> n;
    vector<ii> ct(n + 1);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ct[x] = {ct[x].first + y, ct[x].second + 1};
    }
    sort(ct.begin(), ct.end(), [&](ii a, ii b) {
        return a.second > b.second;
    });
    priority_queue<ii> pq;
    ll cur = ct[0].second;
    int pt = 0;
    ll ans = 0, good = 0;
    while(true) {
        if(cur < 0)
            break;
        while(pt < n + 1 && ct[pt].second >= cur) {
            pq.push(ct[pt]);
            pt++;
        }
        if(pq.empty()) {
            cur--;
            continue;
        }
        auto p = pq.top();
        pq.pop();
        good += min(cur, p.first);
        ans += cur;
        cur--;
    }
    cout << ans << " " << good << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}