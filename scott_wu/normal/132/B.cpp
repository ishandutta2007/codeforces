#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int n, r, c;
int map[60][60];
int next[60][60][4][2];

int xc[4] = {0, 1, 0, -1};
int yc[4] = {1, 0, -1, 0};

void solve (int cr, int cc, int dp, int cp)
{
    int ocr = cr;
    int occ = cc, odp = dp, ocp = cp;
    int ccolor = map[cr][cc];
    while (map[cr+xc[dp]][cc+yc[dp]] == ccolor)
    {
        cr+=xc[dp]; cc+=yc[dp];
    }
    int np = (dp + cp * 2 + 3) % 4;
    while (map[cr+xc[np]][cc+yc[np]] == ccolor)
    {
        cr+=xc[np]; cc+=yc[np];
    }
    if (map[cr+xc[dp]][cc+yc[dp]] > 0)
    {
        int nx = cr + xc[dp];
        int ny = cc + yc[dp];
        next[ocr][occ][odp][ocp] = 480 * nx + 8 * ny + 2 * dp + cp;
    }
    else
    {
        if (cp == 1)
            dp = (dp + 1) % 4;
        cp = 1 - cp;
        next[ocr][occ][odp][ocp] = 480 * ocr + 8 * occ + 2 * dp + cp;
    }
}

int main()
{
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 60; j++)
            map[i][j] = 0;
    cin >> r >> n;
    string str;
    for (int i = 1; i <= r; i++)
    {
        cin >> str;
        c = str.length();
        for (int j = 1; j <= c; j++)
            map[i][j] = (int) str[j-1] - '0';
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (map[i][j] != 0)
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 2; l++)
                        solve (i, j, k, l);
    int cur = 488;
    for (int i = 0; i < n; i++)
    {
        cur = next[cur/480][(cur%480)/8][(cur%8)/2][cur%2];
        //cout << map[cur/480][(cur%480)/8] << " ";
        //cout << (cur%8)/2 << " " << cur%2 << "\n";
    }
    cout << map[cur/480][(cur%480)/8] << "\n";
    //system ("Pause");
    return 0;
}