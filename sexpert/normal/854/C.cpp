#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1), times(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    priority_queue<ii> pq;
    ll td = 0, ans = 0;
    for(int i = 1; i <= min(n, k); i++) {
        pq.emplace(v[i], i);
        td += v[i];
        ans += (k - i + 1)*v[i];
    }
    for(int t = k + 1; t <= k + n; t++) {
        if(t <= n) {
            pq.emplace(v[t], t);
            td += v[t];
        }
        auto p = pq.top();
        pq.pop();
        td -= p.first;
        times[p.second] = t;
        ans += td;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << times[i] << " ";
    cout << endl;
}