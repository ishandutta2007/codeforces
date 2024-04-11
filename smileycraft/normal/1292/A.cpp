
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n, q;
    cin >> n >> q;
    vector<vector<bool>> grid(2, vector<bool>(n, true));
    vector<bool> pass(n - 1, true);
    ll passes = n - 1;
    while (--q >= 0){
        ll x, y;
        cin >> x >> y;
        --x, --y;
        grid[x][y] = !grid[x][y];
        bool b1 = y - 1 >= 0 && ((grid[0][y - 1] && grid[0][y]) || (grid[1][y - 1] && grid[1][y])),
            b2 = y + 1 < n && ((grid[0][y + 1] && grid[0][y]) || (grid[1][y + 1] && grid[1][y]));
        if (y - 1 >= 0 && b1 && !pass[y - 1]) ++passes;
        if (y - 1 >= 0 && !b1 && pass[y - 1]) --passes;
        if (y - 1 >= 0) pass[y - 1] = b1;
        if (y + 1 < n && b2 && !pass[y]) ++passes;
        if (y + 1 < n && !b2 && pass[y]) --passes;
        if (y + 1 < n) pass[y] = b2;
        if (passes == n - 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}