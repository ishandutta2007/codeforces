#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int K = 8;
const int N = K * K;
const int LOGN = 35;
const int MOD = 998244353;
const int INF = 1e9 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }


    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }

    sort(b.rbegin(), b.rend());

    if(n == 1) {
        cout << sum - b[0] << endl;
    } else {
        cout << sum - b[0] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}