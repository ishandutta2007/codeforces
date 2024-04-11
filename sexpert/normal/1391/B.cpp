#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> gr(n);
        for(auto &s : gr)
            cin >> s;
        int cnt = 0;
        for(int i = 0; i < n - 1; i++)
            cnt += (gr[i][m - 1] == 'R');
        for(int j = 0; j < m - 1; j++)
            cnt += (gr[n - 1][j] == 'D');
        cout << cnt << '\n';
    }    
}