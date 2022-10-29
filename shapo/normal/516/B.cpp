#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <utility>
#include <tuple>

using namespace std;

const int MAXN = 2005;

const int DX[4] = {0, 1, 0, -1};
const int DY[4] = {1, 0, -1, 0};
const char *DC = "<^>v";

int n, m;
bool used[MAXN][MAXN];
char s[MAXN][MAXN];
pair< int, int > q[MAXN * MAXN * 4];
int wh_cnt, bl_cnt;

inline bool
is_in(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool
can_construct()
{
    if (wh_cnt != bl_cnt) {
        return false;
    }
    int qh = 0, qt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                q[qt++] = make_pair(i, j);
            }
        }
    }
    while (qh < qt) {
        int x, y;
        tie(x, y) = q[qh++];
        if (s[x][y] != '.') {
            continue;
        }
        int cnt = 0;
        for (int d = 0; d < 4; ++d) {
            if (is_in(x + DX[d], y + DY[d]) && s[x + DX[d]][y + DY[d]] == '.') {
                ++cnt;
            }
        }
        if (cnt != 1) {
            continue;
        }
        //cerr << "process " << x << " " << y << endl;
        int dir = 0;
        while (dir < 4) {
            if (is_in(x + DX[dir], y + DY[dir]) && s[x + DX[dir]][y + DY[dir]] == '.') {
                break;
            }
            ++dir;
        }
        if (dir == 4) {
            return false;
        }
        int cx = x + DX[dir], cy = y + DY[dir];
        s[x][y] = DC[dir];
        s[cx][cy] = DC[(dir + 2) % 4];
        //cerr << "get " << cx << " " << cy << endl;
        for (int d = 0; d < 4; ++d) {
            if (is_in(cx + DX[d], cy + DY[d]) && s[cx + DX[d]][cy + DY[d]] == '.') {
                q[qt++] = make_pair(cx + DX[d], cy + DY[d]);
            }
        }
    }
    //cerr << "here" << endl;
    /*for (int i = 0; i < n; ++i) {
        puts(s[i]);
    }*/
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", s[i]);
    }
    wh_cnt = bl_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = (s[i][j] == '*');
            if (s[i][j] != '*') {
                if ((i + j) % 2 == 0) {
                    wh_cnt++;
                } else {
                    bl_cnt++;
                }
            }
        }
    }
    if (can_construct()) {
        for (int i = 0; i < n; ++i) {
            puts(s[i]);
        }
    } else {
        puts("Not unique");
    }
    return 0;
}