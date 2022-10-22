#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int A = 26;
const int B = 400;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[mx] < a[i])
            mx = i;
//        mx = max(mx, a[i]);
    }

    cout << mx + 1 << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}