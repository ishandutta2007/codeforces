#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int d[4], a[4], i, r, tr;

int gw(int d1, int a1, int d2, int a2)
{
    if ((d1 > a2) && (a1 > d2)) return 1;
    if ((d2 > a1) && (a2 > d1)) return -1;
    return 0;
}

int main()
{
    fortodo(i, 0, 3) scanf("%d%d", &d[i], &a[i]);
    r = max(min(gw(d[0], a[1], d[2], a[3]), gw(d[0], a[1], d[3], a[2])),
            min(gw(d[1], a[0], d[2], a[3]), gw(d[1], a[0], d[3], a[2])));
    if (r == -1) printf("Team 2\n");
    if (r == 0) printf("Draw\n");
    if (r == 1) printf("Team 1\n");
}