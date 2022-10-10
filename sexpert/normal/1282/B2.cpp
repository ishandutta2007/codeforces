#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;
int n, p, k;

void solve() {
    cin >> n >> p >> k;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    vector<int> cost(n + 1);
    for(int i = 1; i < k; i++)
        cost[i] = v[i - 1] + cost[i - 1];
    for(int i = k; i <= n; i++)
        cost[i] = v[i - 1] + cost[i - k];
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        if(cost[i] <= p)
            ans = i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}