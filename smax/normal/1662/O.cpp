#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
#define f first
#define s second
// const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<bool>> l(21, vector<bool>(360, true)), r(21, vector<bool>(360, true)), out(21, vector<bool>(360, true)), in(21, vector<bool>(360, true));
        vector<vector<bool>> visited(21, vector<bool>(360));
        for (int tt = 1; tt <= n; tt++) {
            char type;
            cin >> type;
            if (type == 'S') {
                int r1, r2, theta;
                cin >> r1 >> r2 >> theta;
                int lef = (theta + 359) % 360;
                int rig = theta;
                for (int i = r1; i <= r2 - 1; i++) {
                    r[i][lef] = false;
                    l[i][rig] = false;
                }
            } else {
                // type = 'C'
                int r, theta1, theta2;
                cin >> r >> theta1 >> theta2;
                vector<pi> ranges;
                if (theta1 <= theta2) ranges.pb({theta1, theta2 - 1});
                else {
                    ranges.pb({theta1, 359});
                    if (theta2 > 0) ranges.pb({0, theta2 - 1});
                }
                for (pi p: ranges) {
                    for (int i = p.f; i <= p.s; i++) {
                        out[r-1][i] = false;
                        in[r][i] = false;
                    }
                }
            }
        }
        function<void(int, int)> dfs = [&](int rad, int theta) {
            int theta1 = (theta + 359) % 360;
            int theta2 = (theta + 1) % 360;
            visited[rad][theta] = true;
            if (r[rad][theta] and !visited[rad][theta2]) {
                dfs(rad, theta2);
            }
            if (l[rad][theta] and !visited[rad][theta1]) {
                dfs(rad, theta1);
            }
            if (in[rad][theta] and rad >= 1 and !visited[rad-1][theta]) {
                dfs(rad-1, theta);
            }
            if (out[rad][theta] and rad < 20 and !visited[rad+1][theta]) {
                dfs(rad+1, theta);
            }
        };
        dfs(0, 0);
        if (visited[20][0]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}