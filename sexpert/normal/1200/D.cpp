#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2007;
string board[MAXN];
int row[MAXN], col[MAXN], rsp[MAXN][MAXN], csp[MAXN][MAXN], em;
int val[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = (board[i][j] == 'B' ? '1' : '0');
    for(int i = 0; i < n; i++) {
        int le = -1, ri = -1;
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '1') {
                le = j;
                break;
            }
        }
        if(le == -1) {
            em++;
            continue;
        }
        for(int j = n - 1; j >= 0; j--) {
            if(board[i][j] == '1') {
                ri = j;
                break;
            }
        }
        if(ri - le < k) {
            for(int ro = max(0, i - k + 1); ro <= i; ro++) {
                rsp[ro][max(0, ri - k + 1)]++;
                rsp[ro][le + 1]--;
            }
        }
    }
    for(int j = 0; j < n; j++) {
        int le = -1, ri = -1;
        for(int i = 0; i < n; i++) {
            if(board[i][j] == '1') {
                le = i;
                break;
            }
        }
        if(le == -1) {
            em++;
            continue;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(board[i][j] == '1') {
                ri = i;
                break;
            }
        }
        if(ri - le < k) {
            //cout << "column " << j << endl;
            for(int co = max(0, j - k + 1); co <= j; co++) {
                csp[max(0, ri - k + 1)][co]++;
                csp[le + 1][co]--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < n; j++) {
            cur += rsp[i][j];
            val[i][j] += cur;
        }
    }
    for(int j = 0; j < n; j++) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += csp[i][j];
            val[i][j] += cur;
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mx = max(mx, val[i][j]);
    cout << em + mx << '\n';
}