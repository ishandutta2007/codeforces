#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <functional>

#define maxn 200000
#define maxk 131072

using namespace std;

struct point{
    int x, y;
};

int cur[maxn], res[maxn][3];
point dff[maxn];
int i, k, n;
point tree[2 * maxk + 100];

point min_l(const point &x, const point &y){
    point res;
    if (x.y >= y.y) res = x; else res = y;
    return res;
}

int update(const int &x, const int &y){
    tree[x].y = y;
    int par = (x / 2);
    while (par > 0){
        tree[par] = min_l(tree[2 * par], tree[2 * par + 1]);
        par = par / 2;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2 * maxk + 100; ++i){tree[i].x = i; tree[i].y = 0;}
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)scanf("%d", &cur[i]);
    sort(cur, cur + n);
    int num1 = 1;
    dff[1].x = cur[n - 1];
    dff[1].y = 1;
    for (int i = n - 1; i > 0; --i)
        if (cur[i] != cur[i - 1]){
            ++num1;
            dff[num1].x = cur[i - 1];
            dff[num1].y = 1;
        }
        else ++dff[num1].y;
    for (int i = maxk; i < maxk + num1; ++i){
        tree[i].x = i;
        tree[i].y = dff[i - maxk + 1].y;
    }
    for (int i = maxk - 1; i > 0; --i) tree[i] = min_l(tree[2 * i], tree[2 * i + 1]);
    int rss = 0;
    point l1 = tree[1];
    update(l1.x, 0);
    point l2 = tree[1];
    update(l2.x, 0);
    point l3 = tree[1];
    update(l3.x, 0);
    while (l3.y > 0){
        update(l1.x, l1.y - 1);
        update(l2.x, l2.y - 1);
        update(l3.x, l3.y - 1);
        ++rss;
        if (l1.x >= maxk) res[rss][0] = dff[l1.x - maxk + 1].x;
        if (l2.x >= maxk) res[rss][1] = dff[l2.x - maxk + 1].x;
        if (l3.x >= maxk) res[rss][2] = dff[l3.x - maxk + 1].x;
        sort(res[rss], res[rss] + 3);
        l1 = tree[1];
        if (l1.x >= maxk) update(l1.x, 0);
        l2 = tree[1];
        if (l2.x >= maxk) update(l2.x, 0);
        l3 = tree[1];
        if (l3.x >= maxk) update(l3.x, 0);
    }
    printf("%d\n", rss);
    for (int i = 1; i <= rss; ++i){
        printf("%d %d %d\n", res[i][2], res[i][1], res[i][0]);
    }
    return 0;
}