#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

int n, v;
int p1 = 0, p2 = 0;
int d[110000];
int n1[110000], n2[110000];
int d1[110000], d2[110000];

bool comp(int a, int b) {return (d[a] > d[b]);}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        d[i] = b;
        if (a == 1) p1 ++, n1[p1] = i;
        if (a == 2) p2 ++, n2[p2] = i;
    }

    sort(n1 + 1, n1 + p1 + 1, comp);
    sort(n2 + 1, n2 + p2 + 1, comp);

    d1[0] = d2[0] = 0;
    for (int i = 1; i <= p1; i ++)
        d1[i] = d1[i - 1] + d[n1[i]];
    for (int i = 1; i <= p2; i ++)
        d2[i] = d2[i - 1] + d[n2[i]];

    int res = 0, r = 0, s = 0;

    for (int i = 0; i <= p1 && i <= v; i ++)
    {
        int q = (v - i) / 2;
        if (q > p2) q = p2;
        if (d1[i] + d2[q] > res) res = d1[i] + d2[q], r = i, s = q;
    }

    printf("%d\n", res);
    for (int i = 1; i <= r; i ++)
        printf("%d ", n1[i]);
    for (int i = 1; i <= s; i ++)
        printf("%d ", n2[i]);
    return 0;
}