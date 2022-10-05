// I hope one day I'll be at least half as cool as dsgrekova
#include <bits/stdc++.h>
//#pragma GCC optimise("O3")
//#pragma GCC optimise("unroll-loops")
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
const int INF = 1e9 + 7;

int factorial(int x) {
    if (x < 2) {
        return 1;
    }
    return (x * factorial(x - 1)) % INF;
}

void solve() {
    int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    map<int, int> chill;
    for (int e : s) {
        ++chill[e];
    }
    int flex = s[0];
    for (int e : s) {
        flex &= e;
    }
    cout << (((chill[flex] * (chill[flex] - 1)) % INF) * factorial(n - 2)) % INF << endl;
}

signed main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    cout.setf(ios::fixed);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}