#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int board[1005][1005];
vector<int> row[1005], col[1005];
set<int> cur;

int nl(vector<int> &v, int bnd) {
    int lo = 0, hi = v.size() - 1;
    if(v[0] >= bnd)
        return 0;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(v[mi] < bnd)
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo + 1;
}

int ng(vector<int> &v, int bnd) {
    int lo = 0, hi = v.size() - 1;
    if(v[hi] <= bnd)
        return 0;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(v[mi] > bnd)
            hi = mi;
        else
            lo = mi + 1;
    }
    return v.size() - lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int l, u;
    for(int r = 0; r < n; r++) {
        cur.clear();
        for(int i = 0; i < m; i++) {
            if(!cur.count(board[r][i])) {
                row[r].push_back(board[r][i]);
                cur.insert(board[r][i]);
            }
        }
        sort(row[r].begin(), row[r].end());
    }

    for(int c = 0; c < m; c++) {
        cur.clear();
        for(int i = 0; i < n; i++) {
            if(!cur.count(board[i][c])) {
                col[c].push_back(board[i][c]);
                cur.insert(board[i][c]);
            }
        }
        sort(col[c].begin(), col[c].end());
    }

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            int l1 = nl(row[r], board[r][c]), l2 = nl(col[c], board[r][c]);
            int r1 = ng(row[r], board[r][c]), r2 = ng(col[c], board[r][c]);
            cout << max(l1, l2) + max(r1, r2) + 1 << " ";
        }
        cout << endl;
    }
}