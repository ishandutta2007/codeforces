#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

int n, k;
int a[N], b[N];

pli solve(ll x) {
    ll res = 0;
    priority_queue<ll, vector<ll>, greater<> > pq2;
    priority_queue<ll> pq1;
    for(int i = 0; i < n; i++) {
        pq2.push(a[i]);
        ll c1 = pq1.empty() ? INF : b[i] - pq1.top();
        ll c2 = b[i] + pq2.top() - x;
        if(c1 < c2 && c1 < 0) {
            // rematch
            res += c1;
            pq1.pop();
            pq1.push(b[i]);
        }
        else if(c2 <= c1 && c2 <= 0) {
            // match new
            res += c2;
            pq2.pop();
            pq1.push(b[i]);
        }
    }
    return {res, pq1.size()};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll l = 0, r = (ll)3e9, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        auto p = solve(mid);
        if(p.second <= k) l = mid;
        else r = mid;
    }
    auto p = solve(l);
//    cout << k << endl;
    cout << p.first + l * p.second << endl;
}