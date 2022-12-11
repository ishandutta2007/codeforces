#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;

int dp[16384][6][42];
int w, h;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> w >> h;

    for (int i = 0; i < 16384; i++)
        for (int j = 0; j < 6; j++)
            for (int ii = 0; ii < 42; ii++)
                dp[i][j][ii] = w * h + 1000000;

    if (w < h)
        swap(h, w);
    if (h == 1) {
        int ans = (w / 3) * 2;
        if (w % 3 == 2) ans++;
        cout << ans;
        return 0;
    }

    int xx, yy, msk = 0;
    bool ok;

    for (int i = 0; i < h; i++)
        msk |= (1 << (2 * i));
    dp[msk][0][0] = 0;

    for (int x = 0; x <= w; x++)
    for (int y = 0; y < h; y++)
    for (int mask = 0; mask < (4 << (2 * h)); mask++) {

        ok = true;
        for (int i = 0; i <= h; i++)
            if ((mask & (3 << (i * 2))) == 2)
                ok = false;
        if (!ok || dp[mask][y][x] > w * h)
            continue;

        //cerr << mask << " " << y << " " << x << " -> " << dp[mask][y][x] << "\n";

        xx = x;
        yy = y + 1;
        if (yy == h) {
            yy = 0;
            xx++;
        }

        if (mask & 3) {
            msk = mask >> 2;
            if ((msk & 2) || ((mask & (2 << (2 * h))) && yy > 0))
                msk |= (1 << (2 * h));

            //cerr << "  " << msk << " " << yy << " " << xx << " +0\n";
            dp[msk][yy][xx] = min(dp[msk][yy][xx], dp[mask][y][x]);
        }

        if (xx > 0 && yy > 0) {
            msk = mask >> 2;
            if ((msk & 2) || ((mask & (2 << (2 * h))) && yy > 0))
                msk |= (1 << (2 * h));
            msk |= (yy + 1 == h ? 3 : 7) | (1 << (2 * h));
            //cerr << "  " << msk << " " << yy << " " << xx << " +1\n";
            dp[msk][yy][xx] = min(dp[msk][yy][xx], dp[mask][y][x] + 1);
        }

        msk = mask >> 2;
        if ((msk & 2) || ((mask & (2 << (2 * h))) && yy > 0))
            msk |= (1 << (2 * h));
        if (yy + 1 == h) msk |= 1;
        msk |= (1 << (2 * h - 2));
        dp[msk][yy][xx] = min(dp[msk][yy][xx], dp[mask][y][x] + 1);

        msk = mask >> 2;
        if ((msk & 2) || ((mask & (2 << (2 * h))) && yy > 0))
            msk |= (1 << (2 * h));
        msk |= (3 << (2 * h - 2));
        if (yy != 0)
            msk |= (1 << (2 * h));
        if (yy != 1)
            msk |= (1 << (2 * h - 4));
        //cerr << "  " << msk << " " << yy << " " << xx << " +1\n";
        dp[msk][yy][xx] = min(dp[msk][yy][xx], dp[mask][y][x] + 1);
    }

    int ans = w * h;
    for (int mask = 0; mask < (4 << (2 * h)); mask++) {
        ans = min(ans, dp[mask][0][w + 1]);
    }

    cout << h * w - ans;

    return 0;
}