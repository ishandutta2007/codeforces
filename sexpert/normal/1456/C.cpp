#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
ll pans[MAXN], sans[MAXN], sts[MAXN], res[MAXN], ssum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    priority_queue<ll> q;
    for(int i = 0; i <= k; i++)
        q.push(0);
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.rbegin(), v.rend());
    for(auto &x : v) {
        ll s = q.top(); q.pop();
        ans += s;
        q.push(s + x);
    }
    cout << ans << '\n';
}