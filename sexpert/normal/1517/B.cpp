#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ru(n, vector<int>(m)), ans;
    vector<array<int, 2>> guys;
    ans = ru;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ru[i][j];
            guys.push_back({ru[i][j], i});
        }    
    }
    sort(guys.begin(), guys.end());
    for(int i = 0; i < n; i++)
        sort(ru[i].rbegin(), ru[i].rend());
    for(int j = 0; j < m; j++) {
        int r = guys[j][1];
        int x = ru[r].back(); ru[r].pop_back();
        ans[r][j] = x;
    }
    for(int i = 0; i < n; i++) {
        int p = 0;
        for(int j = 0; j < ru[i].size(); j++) {
            while(ans[i][p])
                p++;
            ans[i][p++] = ru[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}