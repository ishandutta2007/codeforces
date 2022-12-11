#include <bits/stdc++.h>
using namespace std;

void solve(int k) {
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);

    if (n % (k + 1) == 0) {
        cout << "+\n";
        return;
    }

    int nid = (n + m) % 2;
    if (n % (k * 2 + 2) / (k + 1) == 1 && k > 1) nid = 1 - nid;

    cout << (nid ? "+\n" : "-\n");
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, k;
    cin >> t >> k;
    while (t--) {
        solve(k);
    }
}