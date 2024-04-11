#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;
using ld = long double;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << (a[0] + a[1] <= d || a[n - 1] <= d ? "Yes" : "No") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}