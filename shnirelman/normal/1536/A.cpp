#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int LOGN = 20;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = INF, mx = -INF;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(mn < 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl << 300 << endl;
    for(int i = 0; i < 300; i++) {
        cout << i << ' ';
    }
    cout << endl;

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}