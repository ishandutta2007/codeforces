#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int a[3];
    int d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    cout << max(0, d - (a[1] - a[0])) + max(0, d - (a[2] - a[1])) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 4;
    for (int i = 1; i < T; i++) solve();    
#endif
}