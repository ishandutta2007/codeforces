#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pl> pairs(n);
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pairs[i] = {y, x};
    }
    sort(pairs.begin(), pairs.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ksum = 0, ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ll curB = pairs[i].first;
        if(pq.size() < k) {
            pq.push(pairs[i].second);
            ksum += pairs[i].second;
        }
        else {
            if(pairs[i].second > pq.top()) {
                ksum -= pq.top();
                pq.pop();
                ksum += pairs[i].second;
                pq.push(pairs[i].second);
            }
        }
        ans = max(ans, curB * ksum);
    }
    cout << ans << endl;
}