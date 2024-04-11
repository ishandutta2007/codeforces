#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define maxn 350000
#define maxk 524288

int tree[2 * maxk];
int curk;
int pos[maxn];
int a[maxn];
int n;

int add(int pos, int val)
{
    //printf("add %d %d\n", pos, val);
    tree[pos + curk - 1] += val;
    int par = (pos + curk - 1) / 2;
    while (par != 0)
    {
        tree[par] = tree[par * 2] + tree[par * 2 + 1];
        par /= 2;
    }
    return 0;
}

int getsum(int x, int y)
{
    x += curk - 1;
    y += curk - 1;
    int sum = 0;
    while (x < y)
    {
        if (x % 2 == 1)
        {
            sum += tree[x];
        }
        if (y % 2 == 0)
        {
            sum += tree[y];
        }
        x = (x + 1) / 2;
        y = (y - 1) / 2;
    }
    if (x == y)
    {
        sum += tree[x];
    }
    return sum;
}

int change(int oldx, int oldy, int newx, int newy, int x)
{
    if (x == 1 || x > n)
    {
        return 0;
    }
    //printf("ch %d %d\n", x, x - 1);
    //x = x, y = x - 1;
    if (oldx > oldy && newx < newy)
    {
        add(x, 1);
    }
    if (oldy > oldx && newy < newx)
    {
        add(x, -1);
    }
    return 0;
}

int proc(int px, int py)
{
    if (abs(a[px] - a[py]) <= 1)
    {
        int x = a[px], y = a[py];
        if (x > y)
        {
            add(x, -1);
            change(py, pos[y - 1], px, pos[y - 1], y);
            change(pos[x + 1], px, pos[x + 1], py, x + 1);
        }
        else
        {
            add(y, 1);
            change(px, pos[x - 1], py, pos[x - 1], x);
            change(pos[y + 1], py, pos[y + 1], px, y + 1);
        }
        a[px] = y;
        a[py] = x;
        pos[x] = py;
        pos[y] = px;
        return 0;
    }
    int x = a[px], y = a[py];
    change(px, pos[x - 1], py, pos[x - 1], x);
    change(pos[x + 1], px, pos[x + 1], py, x + 1);
    change(py, pos[y - 1], px, pos[y - 1], y);
    change(pos[y + 1], py, pos[y + 1], px, y + 1);
    a[px] = y;
    a[py] = x;
    pos[x] = py;
    pos[y] = px;
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    curk = 2;
    while (curk < n)
    {
        curk *= 2;
    }
    for (int i = 1; i < n; ++i)
    {
        //printf("pos[%d] = %d\n", i, pos[i]);
        if (pos[i] > pos[i + 1])
        {
            add(i + 1, 1);
        }
    }
    int q;
    scanf("%d", &q);
    /*for (int i = 1; i <= 2 * curk - 1; ++i)
    {
        printf("tree[%d] = %d\n", i, tree[i]);
    }*/
    /*for (int it = 1; it <= n; ++it)
    {
        printf("get[%d] = %d\n", it, tree[curk + it - 1]);
    }*/
    for (int i = 1; i <= q; ++i)
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        //printf("p = %d\n", p);
        if (p == 1)
        {
            printf("%d\n", getsum(x + 1, y) + 1);
        }
        else
        {
            proc(x, y);
            /*for (int it = 1; it <= n; ++it)
            {
                printf("get[%d] = %d\n", it, tree[curk + it - 1]);
            }*/
        }
    }
    return 0;
}