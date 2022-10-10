#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tot = 0;
    cin >> n >> m;
    vector<int> r(n), c(m);
    for(auto &x : r) {
        cin >> x;
        tot ^= x;
    }
    for(auto &x : c) {
        cin >> x;
        tot ^= x;
    }
    if(tot != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<vector<int>> res(n, vector<int>(m));
    int www = 0;
    for(int i = 0; i < m - 1; i++) {
        res[0][i] = c[i];
        www ^= c[i];
    }
    res[0][m - 1] = r[0] ^ www;
    for(int i = 1; i < n; i++)
        res[i][m - 1] = r[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;
}