#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<int, 2> swp = {-1, -1};
    int p = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(auto &x : v[i])
            cin >> x;

    vector<vector<int>> sv = v;
    for(int i = 0; i < n; i++)
        sort(sv[i].begin(), sv[i].end());

    for(int i = 0; i < n; i++) {
        if(p == 2)
            continue;
        for(int j = 0; j < m; j++) {
            if(p == 2)
                break;
            if(v[i][j] != sv[i][j])
                swp[p++] = j;
        }
    }

    if(swp[0] == -1) {
        cout << "1 1\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        swap(v[i][swp[0]], v[i][swp[1]]);
        if(v[i] != sv[i]) {
            cout << "-1\n";
            return;
        }
    }

    cout << swp[0] + 1 << " " << swp[1] + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}