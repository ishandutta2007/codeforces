#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
set<int> rows[26], cols[26];
char board[2010][2010];
int ovr, ovc;
array<int, 4> ans[26];
 
void solve() {
    int n, m, big = -1;
    cin >> n >> m;
    for(int i = 0; i < 26; i++) {
        rows[i].clear();
        cols[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if(board[i][j] == '.') continue;
            rows[board[i][j] - 'a'].insert(i);
            cols[board[i][j] - 'a'].insert(j);
            big = max(big, board[i][j] - 'a');
        }
    }
    if(big == -1) {
        cout << "YES\n";
        cout << "0\n";
        return;
    }
    for(int i = 0; i < 26; i++){
        if(cols[i].size() > 1 && rows[i].size() > 1) {
            cout << "NO\n";
            return;
        }
        if(cols[i].size() > 0 && rows[i].size() > 0) {
            ovr = *(rows[i].begin());
            ovc = *(cols[i].begin());
        }
    }
    for(int c = 0; c <= big; c++) {
        if(rows[c].empty()) {
            ans[c] = {ovr, ovc, ovr, ovc};
            continue;
        }
        if(rows[c].size() == 1) {
            int x = *(rows[c].begin());
            int l, r;
            for(int i = 1; i <= m; i++) {
                if(board[x][i] == 'a' + c) {
                    l = i;
                    break;
                }
            }
            for(int i = m; i >= 1; i--) {
                if(board[x][i] == 'a' + c) {
                    r = i;
                    break;
                }
            }
            for(int k = l; k <= r; k++) {
                if(board[x][k] - 'a' < c) {
                    cout << "NO\n";
                    return;
                }
            }
            ans[c] = {x, l, x, r};
        }
        else {
            int x = *(cols[c].begin());
            int l, r;
            for(int i = 1; i <= n; i++) {
                if(board[i][x] == 'a' + c) {
                    l = i;
                    break;
                }
            }
            for(int i = n; i >= 1; i--) {
                if(board[i][x] == 'a' + c) {
                    r = i;
                    break;
                }
            }
            for(int k = l; k <= r; k++) {
                if(board[k][x] - 'a' < c) {
                    cout << "NO\n";
                    return;
                }
            }
            ans[c] = {l, x, r, x};
        }
    }
    cout << "YES\n";
    cout << big + 1 << '\n';
    for(int i = 0; i <= big; i++) {
        for(int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
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