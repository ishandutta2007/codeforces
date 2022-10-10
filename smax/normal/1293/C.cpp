#include <bits/stdc++.h>
using namespace std;

bool blocked[2][100000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    int numBlocked = 0;
    for (int i=0; i<q; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        int change = (blocked[r][c] ? -1 : 1);
        blocked[r][c] = !blocked[r][c];
        for (int d=-1; d<=1; d++)
            if (c + d >= 0 && c + d < n && blocked[1-r][c+d])
                numBlocked += change;

        cout << (numBlocked == 0 ? "Yes" : "No") << "\n";
    }

    return 0;
}