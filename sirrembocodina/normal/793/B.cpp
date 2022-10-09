#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef unsigned int uint;

char a[1010][1010];

bool ok(int x1, int y1, int x2, int y2) {
    bool ok = true;
    int dx = x2 > x1 ? 1 : -1;
    int dy = y2 > y1 ? 1 : -1;
    for (int x = x1; x != x2; x += dx) {
        if (a[x][y1] == '*') {
            ok = false;
        }
    }
    for (int y = y1; y != y2; y += dy) {
        if (a[x2][y] == '*') {
            ok = false;
        }
    }
    if (ok) {
        return true;
    }
    ok = true;
    for (int y = y1; y != y2; y += dy) {
        if (a[x1][y] == '*') {
            ok = false;
        }
    }
    for (int x = x1; x != x2; x += dx) {
        if (a[x][y2] == '*') {
            ok = false;
        }
    }
    if (ok) {
        return true;
    }
    return false;
}

int n, m;

bool ok_cell(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '*';
}

int main() {
    scanf("%d%d", &n, &m);
    int sx = 0, sy, tx = 0, ty = 0;
    forn (i, n) {
        scanf("%s", a[i]);
        forn (j, m) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }
    forn (i, n) {
        if (ok_cell(sx + i, sy) && ok(sx + i, sy, tx, ty) && ok(sx + i, sy, sx, sy)) {
            cout << "YES" << endl;
            return 0;
        }
        if (ok_cell(sx - i, sy) && ok(sx - i, sy, tx, ty) && ok(sx - i, sy, sx, sy)) {
            cout << "YES" << endl;
            return 0;
        }
        if (ok_cell(sx, sy + i) && ok(sx, sy + i, tx, ty) && ok(sx, sy + i, sx, sy)) {
            cout << "YES" << endl;
            return 0;
        }
        if (ok_cell(sx, sy - i) && ok(sx, sy - i, tx, ty) && ok(sx, sy - i, sx, sy)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}