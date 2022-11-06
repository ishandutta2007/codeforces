#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<bool> godly(n, true);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            godly[b] = false;
        }
        for (int i = 0; i < n; i++) {
            if (godly[i]) {
                for (int j = 0; j < n; j++) {
                    if (i != j) cout << i + 1 << ' ' << j + 1 << '\n';
                }
                break;
            }
        }
    }

    return 0;
}