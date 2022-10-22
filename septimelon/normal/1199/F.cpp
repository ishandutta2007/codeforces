#include <bits/stdc++.h>

#define MAXN 52

using namespace std;

int n;
int a[MAXN][MAXN];
int q[MAXN][MAXN][MAXN][MAXN];

int mincost (int x0, int y0, int wid, int hei) {
    //cout << x0 << "-" << y0 << "-" << wid << "-" << hei << ": ";
    if (wid == 0 || hei == 0 || x0 >= n || y0 >= n)
        return 0;
    if (q[x0][y0][wid][hei] >= 0)
        return q[x0][y0][wid][hei];
    vector<int> cou(max(wid, hei) + 1, 0);
    cou[cou.size()-1] = 10000;
    int minco, maxco;
    int curi = 0;
    int curl, ans;
    if (wid > hei) {
        for (int i = 0; i < hei; i++) {
            for (int j = 0; j < wid; j++) {
                cou[j] += a[y0+i][x0+j];
            }
        }
        minco = 1;
        maxco = 0;
        for (int i = 0; i < wid; i++) {
            minco = min(minco, cou[i]);
            maxco = max(maxco, cou[i]);
        }
        if (minco > 0) {
            q[x0][y0][wid][hei] = wid;
            //cout << q[x0][y0][wid][hei] << endl;
            return wid;
        }
        if (maxco == 0) {
            q[x0][y0][wid][hei] = 0;
            //cout << q[x0][y0][wid][hei] << endl;
            return 0;
        }
        curi = 0;
        ans = wid;
        while (curi < wid) {
            if (cou[curi] == 0) {
                curl = curi;
                while (cou[curi+1] == 0)
                    curi++;
                ans = min(ans, mincost(x0, y0, curl, hei) + mincost(x0+curi+1, y0, wid-curi-1, hei));
            }
            curi++;
        }
        q[x0][y0][wid][hei] = ans;
        //cout << "ans " << q[x0][y0][wid][hei] << endl;
        return ans;
    }
    else {
        for (int i = 0; i < hei; i++) {
            for (int j = 0; j < wid; j++) {
                cou[i] += a[y0+i][x0+j];
            }
        }
        minco = 1;
        maxco = 0;
        for (int i = 0; i < hei; i++) {
            minco = min(minco, cou[i]);
            maxco = max(maxco, cou[i]);
        }
        if (minco > 0) {
            q[x0][y0][wid][hei] = hei;
            //cout << q[x0][y0][wid][hei] << endl;
            return hei;
        }
        if (maxco == 0) {
            q[x0][y0][wid][hei] = 0;
            //cout << q[x0][y0][wid][hei] << endl;
            return 0;
        }
        curi = 0;
        ans = hei;
        while (curi < hei) {
            if (cou[curi] == 0) {
                curl = curi;
                while (cou[curi+1] == 0)
                    curi++;
                ans = min(ans, mincost(x0, y0, wid, curl) + mincost(x0, y0+curi+1, wid, hei-curi-1));
            }
            curi++;
        }
        q[x0][y0][wid][hei] = ans;
        //cout << "ans " << q[x0][y0][wid][hei] << endl;
        return ans;
    }
}

int main()
{
    cin >> n;
    char c;
    for (int i1 = 0; i1 < MAXN; i1++)
        for (int i2 = 0; i2 < MAXN; i2++)
            for (int i3 = 0; i3 < MAXN; i3++)
                for (int i4 = 0; i4 < MAXN; i4++)
                    q[i1][i2][i3][i4] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    cout << mincost(0, 0, n, n) << endl;
    return 0;
}