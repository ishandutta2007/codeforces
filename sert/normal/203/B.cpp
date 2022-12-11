#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

typedef int ll;

const ll N = 2014;

int n, m, x, y;
bool u[N][N];

void check(int xx, int yy, int num) {
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (!u[xx + i][yy + j])
                return;
    cout << num + 1 << "\n";
    exit(0);
}

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x += 4;
        y += 4;
        u[x][y] = true;
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                check(x + dx, y + dy, i);
    }

    cout << "-1\n";

    return 0;
}