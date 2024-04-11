#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

set < long long > S;
int res;

int a[3][3];

long long code(int x, int y, int z, int mx, int my, int mz, int mode)
{
    long long A = mx * 64 * 512 + my * 8 * 512 + mz * 512 + mode;
    long long B = x * 20000 + y * 110 + z;
    return B * 512LL * 512LL + A;
}

void dfs(int x, int y, int z, int mx, int my, int mz, int mode)
{
	if (x < 1 || y < 1 || z < 1) return ;
    long long h = code(x, y, z, mx, my, mz, mode);
    if (S.count(h)) return ;
    S.insert(h);
    res = max(res, max(x, max(y, z)));

    if ((mx & 1) && !(mode & 2) && !(mode & 4) && !(mode & 8) && !(mode & 64))
    {
        for (int i = -a[0][1]; i <= a[0][1]; i ++)
            if (x + i != y && x + i != z)
                dfs(x + i, y, z, mx ^ 1, my, mz, mode);
    }
    if ((my & 1) && !(mode & 8) && !(mode & 32) && !(mode & 2) && !(mode & 128))
    {
        for (int i = -a[1][1]; i <= a[1][1]; i ++)
            if (y + i != x && y + i != z)
                dfs(x, y + i, z, mx, my ^ 1, mz, mode);
    }
    if ((mz & 1) && !(mode & 64) && !(mode & 128) && !(mode & 4) && !(mode & 32))
    {
        for (int i = -a[2][1]; i <= a[2][1]; i ++)
            if (z + i != x && z + i != y)
                dfs(x, y, z + i, mx, my, mz ^ 1, mode);
    }

    if ((mx & 2) && !(mode & 2) && !(mode & 4) && !(mode & 8) && !(mode & 64))
    {
        if (abs(x - y) == 1 && !(mode & 2) && !(mode & 128))
            dfs(x, x, z, mx ^ 2, my, mz, mode | 2);
        if (abs(x - z) == 1 && !(mode & 4) && !(mode & 32))
            dfs(x, y, x, mx ^ 2, my, mz, mode | 4);
    }

    if ((my & 2) && !(mode & 8) && !(mode & 32) && !(mode & 2) && !(mode & 128))
    {
        if (abs(x - y) == 1 && !(mode & 8) && !(mode & 64))
            dfs(y, y, z, mx, my ^ 2, mz, mode | 8);
        if (abs(y - z) == 1 && !(mode & 4) && !(mode & 32))
            dfs(x, y, y, mx, my ^ 2, mz, mode | 32);
    }

    if ((mz & 2) && !(mode & 64) && !(mode & 128) && !(mode & 4) && !(mode & 32))
    {
        if (abs(z - x) == 1 && !(mode & 8) && !(mode & 64))
            dfs(z, y, z, mx, my, mz ^ 2, mode | 64);
        if (abs(z - y) == 1 && !(mode & 2) && !(mode & 128))
            dfs(x, z, z, mx, my, mz ^ 2, mode | 128);
    }

    if ((mx & 4) && !(mode & 8) && !(mode & 64))
    {
        if ((mode & 2) && !(mode & 128))
        {
            for (int i = - a[0][2]; i <= a[0][2]; i ++)
                if (x + i != y && x + i != z)
                    dfs(x, x + i, ((mode & 32) ? x + i : z), mx ^ 4, my, mz, mode ^ 2);
        }
        if ((mode & 4) && !(mode & 32))
        {
            for (int i = - a[0][2]; i <= a[0][2]; i ++)
                if (x + i != y && x + i != z)
                    dfs(x, ((mode & 128) ? x + i : y), x + i, mx ^ 4, my, mz, mode ^ 4);
        }
    }

    if ((my & 4) && !(mode & 2) && !(mode & 128))
    {
        if ((mode & 8) && !(mode & 64))
        {
            for (int i = - a[1][2]; i <= a[1][2]; i ++)
                if (y + i != x && y + i != z)
                    dfs(y + i, y, ((mode & 4) ? y + i : z), mx, my ^ 4, mz, mode ^ 8);
        }
        if ((mode & 32) && !(mode & 4))
        {
            for (int i = - a[1][2]; i <= a[1][2]; i ++)
                if (y + i != x && y + i != z)
                    dfs(((mode & 64) ? y + i : x), y, y + i, mx, my ^ 4, mz, mode ^ 32);
        }
    }

    if ((mz & 4) && !(mode & 4) && !(mode & 32))
    {
        if ((mode & 64) && !(mode & 8))
        {
            for (int i = - a[2][2]; i <= a[2][2]; i ++)
                if (z + i != x && z + i != y)
                    dfs(z + i, ((mode & 2) ? z + i : y), z, mx, my, mz ^ 4, mode ^ 64);
        }
        if ((mode & 128) && !(mode & 2))
        {
            for (int i = - a[2][2]; i <= a[2][2]; i ++)
                if (z + i != x && z + i != y)
                    dfs(((mode & 8) ? z + i : x), z + i, z, mx, my, mz ^ 4, mode ^ 128);
        }
    }
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            cin >> a[i][j];

    res = max(res, a[0][0]);
    res = max(res, a[1][0]);
    res = max(res, a[2][0]);
    dfs(a[0][0], a[1][0], a[2][0], 7, 7, 7, 0);

    printf("%d\n", res);

    return 0;
}