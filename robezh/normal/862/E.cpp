#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n, m, q;
ll sum[N];
ll a[N], b[N];

ll calc(ll cursum) {
    int loc = lower_bound(sum, sum + m - n + 1, cursum) - sum;
    ll res = INF;
    if(loc != m - n + 1) res = min(res, sum[loc] - cursum);
    if(loc > 0) res = min(res, cursum - sum[--loc]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int sign = 1;
    for(int i = 0; i < n; i++) {
        sum[0] += b[i] * sign;
        sum[1] += b[i+1] * sign;
        sign = -sign;
    }
    for(int i = 2; i <= m - n; i++) {
        sum[i] = -sum[i-1] + b[i-1];
        sign = ((n-1) % 2 == 0 ? 1 : -1);
        sum[i] += sign * b[i+(n-1)];
    }
    sort(sum, sum + m - n + 1);
    ll cursum = 0;
    sign = 1;
    for(int i = 0; i < n; i++) {
        cursum += sign * a[i];
        sign = -sign;
    }
    cout << calc(cursum) << "\n";
    for(int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        sign = ((r - l) % 2 == 1 ? 0 : (l % 2 == 0 ? 1 : -1));
        cursum += sign * x;
        cout << calc(cursum) << "\n";
    }

}