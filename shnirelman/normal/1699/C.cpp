#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 30;
const int L = 2001;

int mul(int a, int b) {
    return a * 1ll * b % M;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), wh(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        wh[a[i]] = i;
    }

    int ans = 1;
    int l = wh[0], r = wh[0];
    for(int i = 1; i < n; i++) {
//        cout << "for " << i << ' ' << l << ' ' << r << ' ' << wh[i] << endl;
        int j = wh[i];
        if(j < l)
            l = j;
        else if(j > r)
            r = j;
        else {
            ans = mul(ans, r - l + 1 - i);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}