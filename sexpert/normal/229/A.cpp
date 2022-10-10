#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &x : grid) {
        cin >> x;
        x += x;
    }
    vector<int> cost(m);
    for(int i = 0; i < n; i++) {
        vector<int> res(m, INT_MAX);
        int pv = -1;
        for(int j = 0; j < 2*m; j++) {
            if(grid[i][j] == '1')
                pv = j;
            if(j >= m) {
                if(pv == -1) {
                    cout << "-1\n";
                    return 0;
                }
                res[j - m] = min(res[j - m], j - pv);
            }
        }
        pv = -1;
        for(int j = 2*m - 1; j >= 0; j--) {
            if(grid[i][j] == '1')
                pv = j;
            if(j < m)
                res[j] = min(res[j], pv - j);
        }
        for(int j = 0; j < m; j++)
            cost[j] += res[j];
    }
    cout << *min_element(cost.begin(), cost.end()) << '\n';
}