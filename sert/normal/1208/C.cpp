#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
    vector<vector<int>> k = {{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int pos = (i / 4) * (n / 4) + (j / 4);
            cout << k[i % 4][j % 4] + pos * 16 << " ";
        }
        cout << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    // cin >> tst;
#ifdef MADE_BY_SERT
    D = true;  
    tst = 2;  
    while (tst--) {
        solve();
    }
#else
    while (tst--) solve();
#endif
}