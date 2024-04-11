#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int sum = (a + b + c + n);
    cout << (sum % 3 == 0 && sum / 3 >= max(max(a, b), c) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}