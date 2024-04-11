#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (max(a, b) > min(c, d) && max(c, d) > min(a, b) ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}