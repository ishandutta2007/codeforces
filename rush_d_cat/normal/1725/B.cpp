#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    ll d;
    cin >> n >> d;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = n - 1; i < n; i ++) {
        ll cost = a[i];
        if (i > j) break;
        while (j > i and cost <= d) {
            cost += a[i];
            j --;
        } 
        if (cost > d) ans ++;
    }
    cout << ans << "\n";
}