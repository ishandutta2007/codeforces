#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 30;

int H, W;
int res[MAXN][MAXN];

void gogo()
{
    cin >> H >> W;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            res[i][j] = 0;

    res[0][0] = res[0][W-1] = res[H-1][0] = res[H-1][W-1] = 1;

    for (int i = 2; i <= W - 3; i += 2)
    {
        res[0][i] = res[H-1][i] = 1;
    }
    for (int i = 2; i <= H - 3; i += 2)
    {
        res[i][0] = res[i][W-1] = 1;
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << res[i][j];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}