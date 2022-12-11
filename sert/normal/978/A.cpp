//made by Sert
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int M = 1000;

void solve() {
    int n;
    cin >> n;
    if (n > 50) exit(22);
    vector<bool> u(M + 1);
    vector<int> a(n), res;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 1 || a[i] > M) exit(11);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!u[a[i]]) res.push_back(a[i]);
        u[a[i]] = true;
    }
    cout << res.size() << "\n";
    for (int i = (int)res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}