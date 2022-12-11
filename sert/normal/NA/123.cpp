#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

void solve() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        if (n % 10 == 0) n /= 10;
        else n--;
    }
    cout << n << "\n";
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    solve();
    return 0;
}