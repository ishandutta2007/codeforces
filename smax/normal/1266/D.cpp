#include <bits/stdc++.h>
using namespace std;

long long balance[100000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        balance[u-1] -= d;
        balance[v-1] += d;
    }

    vector<tuple<int, int, long long>> ret;
    int j = 0;
    for (int i=0; i<n; i++)
        while (balance[i] < 0) {
            while (balance[j] <= 0)
                j++;
            long long mn = min(-balance[i], balance[j]);
            balance[i] += mn;
            balance[j] -= mn;
            ret.emplace_back(i+1, j+1, mn);
        }

    cout << ret.size() << "\n";
    for (auto t : ret)
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";

    return 0;
}