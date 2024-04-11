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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<li> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(k == 1) {
        cout << (n - 1) / 2 << endl;
        return;
    }

//    for(int i = 1; i + k < n; i += 2) {
//        a[i] += INF64;
//        a[i + k - 1] += INF64;
//    }

    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        ans += (a[i] > a[i - 1] + a[i + 1]);
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