#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k1, k2, k = 0;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    vector<int> a(n), b(n);
    for(auto &x : a)
        cin >> x;
    for(auto &x : b)
        cin >> x;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
        pq.push(max(a[i], b[i]) - min(a[i], b[i]));

    while(k) {
        int u = pq.top();
        if(u == 0)
            break;
        pq.pop();
        k--;
        u--;
        pq.push(u);
    }
    if(pq.top() == 0) {
        cout << (k % 2) << '\n';
        return 0;
    }
    ll ans = 0;
    while(pq.size()) {
        ll x = pq.top(); pq.pop();
        ans += x*x;
    }
    cout << ans << '\n';
}