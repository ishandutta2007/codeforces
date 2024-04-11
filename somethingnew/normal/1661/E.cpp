#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
vector<vector<int>> seen;
string pole[3];
int l, r;
int t = 1;
vector<int> le, re;
void dfs(int x, int y) {
    if (pole[x][y] == '0')
        return;
    if (seen[x][y])
        return;
    seen[x][y] = t;
    l = min(l, y);
    r = max(r, y);
    for (int d1 = -1; d1 <= 1; d1 += 2) {
        if (x+d1 >= 0 and x + d1 < 3)
            dfs(x+d1, y);
        if (y+d1 >= 0 and y + d1 < seen[0].size())
            dfs(x, y + d1);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    seen.assign(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        cin >> pole[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (seen[i][j] == 0 and pole[i][j] == '1') {
                l = j;r = j;
                dfs(i, j);
                le.push_back(l);
                re.push_back(r);
                t++;
            }
        }
    }
    vector<int> nxtpalk(n+1, n), prevpalk(n+1, -1);
    for (int i = n-1; i >= 0; --i) {
        nxtpalk[i] = nxtpalk[i + 1];
        if (seen[1][i] and seen[1][i] == seen[2][i] and seen[1][i] == seen[0][i])
            nxtpalk[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        prevpalk[i] = prevpalk[i - 1];
        if (seen[1][i - 1])
            prevpalk[i] = i - 1;
    }
    vector<int> pref0(n + 1), pref2(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref0[i] = pref0[i-1] + (pole[0][i-1] == '0');
        pref2[i] = pref2[i-1] + (pole[2][i-1] == '0');
    }
    sort(all(le));
    sort(all(re));
    int q;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--;r--;
        int res = (int)le.size() - (lower_bound(all(re), l) - re.begin()) - (le.end() - lower_bound(all(le), r+1));
        int add = 0;
        if (pole[0][l] != '0' and seen[0][l] == seen[2][l]) {
            if (nxtpalk[l] > r) {
                add++;
            } else if (seen[1][nxtpalk[l]] != seen[0][l] or pref0[nxtpalk[l]+1] - pref0[l] != 0 or pref2[nxtpalk[l]+1] - pref2[l] != 0) {
                add++;
            }
        }
        if (pole[0][r] != '0' and seen[0][r] == seen[2][r]) {
            if (prevpalk[r + 1] < l) {
                add++;
            } else if (seen[1][prevpalk[r + 1]] != seen[0][r] or pref0[r+1] - pref0[prevpalk[r + 1]] != 0 or pref2[r+1] - pref2[prevpalk[r + 1]] != 0) {
                add++;
            }
        }
        if (pref2[r + 1] == pref2[l] and pref0[r+1] == pref0[l])
            add = min(add, 1ll);
        cout << res + add << '\n';
    }

}
/*
12
100101011101
110110010110
010001011101
1
9 9
 */