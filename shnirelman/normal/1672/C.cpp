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
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    int mn = n, mx = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            cnt++;
            mn = min(mn, i + 1);
            mx = max(mx, i);
        }
    }

    if(cnt <= 1) {
        cout << 0 << endl;
    } else {
        cout << max(1, mx - mn) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}