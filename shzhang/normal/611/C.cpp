
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int h, w;
bool good[505][505];
int hor[505][505];
int ver[505][505];
char s[505];

int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= w; j++) {
            if (s[j] == '.') good[i][j] = true;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (good[i][j] && good[i][j+1]) hor[i][j] = 1;
            if (good[i][j] && good[i+1][j]) ver[i][j] = 1;
            hor[i][j] += hor[i-1][j] + hor[i][j-1] - hor[i-1][j-1];
            ver[i][j] += ver[i-1][j] + ver[i][j-1] - ver[i-1][j-1];
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        int ans = hor[r2][c2-1] - hor[r1-1][c2-1] - hor[r2][c1-1] + hor[r1-1][c1-1];
        ans += ver[r2-1][c2] - ver[r2-1][c1-1] - ver[r1-1][c2] + ver[r1-1][c1-1];
        printf("%d\n", ans);
    }
    return 0;
}