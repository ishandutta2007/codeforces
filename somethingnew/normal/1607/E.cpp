#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
pair<int, int> getans(int mnx, int mny) {
    return {-mnx + 1, -mny + 1};
}
void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int mnx = 0, mxx = 0, mny = 0, mxy = 0;
    int x = 0, y = 0;
    pair<int, int> ans = {1, 1};
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            y++;
        } else if (s[i] == 'L') {
            y--;
        } else if (s[i] == 'U') {
            x--;
        } else {
            x++;
        }
        mnx = min(x, mnx);
        mxx = max(x, mxx);
        mny = min(y, mny);
        mxy = max(y, mxy);
        if (mxx - mnx + 1 > n) {
            break;
        }
        if (mxy - mny + 1 > m) {
            break;
        }
        ans = getans(mnx, mny);
    }
    cout << ans.first << ' ' << ans.second << '\n';

}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}