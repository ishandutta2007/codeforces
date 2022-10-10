#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<ll, vector<ll>, greater<ll>> Q;
    int n;
    cin >> n;
    ll ans = 0;
    while(n--) {
        ll x;
        cin >> x;
        if(Q.size() && x > Q.top()) {
            ans += x - Q.top();
            Q.pop();
            Q.push(x);
        }
        Q.push(x);
    }
    cout << ans << '\n';
}