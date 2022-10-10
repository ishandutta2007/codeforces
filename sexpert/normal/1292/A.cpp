#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int board[3][MAXN];
set<int> bad;

void recalc(int x) {
    bad.erase(x);
    if(board[1][x] == 1 && board[2][x] == 1)
        bad.insert(x);
    if(board[1][x] == 1 && board[2][x + 1] == 1)
        bad.insert(x);
    if(board[2][x] == 1 && board[1][x + 1] == 1)
        bad.insert(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    while(q--) {
        int r, c;
        cin >> r >> c;
        board[r][c] ^= 1;
        for(int i = max(c - 1, 1); i <= min(c + 1, n); i++)
            recalc(i);
        cout << (bad.size() == 0 ? "Yes\n" : "No\n");
    }
}