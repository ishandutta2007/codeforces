#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 2e7 + 13;
//const int M = 1e5 + 13;
const int A = 26;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        if(a[i] == 0)
            c0++;
        else if(a[i] == 1)
            c1++;
    }

    li ans = (1ll << c0) * c1;

    cout << ans << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}