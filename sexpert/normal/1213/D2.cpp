#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 5;
ll cost[MAX];
int cnt[MAX];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int x = v[i], cur = 0;
        while(x > 0) {
            if(cnt[x] < k) {
                cost[x] += cur;
                cnt[x]++;
            }
            x /= 2;
            cur++;
        }
    }
    ll ans = 100000000000000;
    for(int i = MAX - 1; i >= 0; i--)
        if(cnt[i] == k) {
            ans = min(ans, cost[i]);
        }
    cout << ans << '\n';
}