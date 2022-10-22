#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1013;
const int LOGN = 10;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = 0;
    for(int i = 0; i < l; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++)
            cnt += ((a[j] >> i) & 1);
        if(cnt * 2 >= n)
            x += (1 << i);
    }

    cout << x << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}