#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 505;

int gr[MAXN][MAXN], n, used, lim;

void dfs(int r, int c, int cl) {
    used++;
    gr[r][c] = cl;
    if(c > 1 && used < lim && !gr[r][c - 1])
        dfs(r, c - 1, cl);
    if(r + 1 <= n && used < lim && !gr[r + 1][c])
        dfs(r + 1, c, cl);
}

void fill(int st, int am) {
    used = 0, lim = am;
    dfs(st, st, am);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fill(i + 1, x);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            cout << gr[i][j] << " ";
        cout << '\n';
    }
}