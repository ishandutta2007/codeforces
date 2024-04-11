#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

struct Item {
    int c, h, t;
};

struct Query {
    int t, b, id;
};

int n, p;
int f[4005][4005];
int fsuf[4005][4005];

Item items[4005];
int answer[20005];
//Query queries[20005];

//int first_avail[20005];
int last_avail[20005];

bool cmp(Item a, Item b)
{
    return a.t < b.t;
}

/*bool cmp2(Query a, Query b)
{
    return a.t < b.t;
}*/

int main()
{
    /* REMEMBER TO DECREMENT TIME */
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &(items[i].c), &(items[i].h), &(items[i].t));
        items[i].t--;
    }
    sort(items + 1, items + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        if (i == 1 || items[i].t / p != items[i-1].t / p) {
            for (int j = 0; j <= 4000; j++) {
                f[i][j] = (j >= items[i].c ? items[i].h : 0);
            }
        } else {
            for (int j = 0; j <= 4000; j++) {
                f[i][j] = max(f[i-1][j], ((j >= items[i].c) ? items[i].h + f[i-1][j-items[i].c] : 0));
            }
        }
    }


    for (int i = n; i >= 1; i--) {
        if (i == n || items[i].t / p != items[i+1].t / p) {
            for (int j = 0; j <= 4000; j++) {
                fsuf[i][j] = (j >= items[i].c ? items[i].h : 0);
            }
        } else {
            for (int j = 0; j <= 4000; j++) {
                fsuf[i][j] = max(fsuf[i+1][j], (j >= items[i].c ? items[i].h + fsuf[i+1][j-items[i].c] : 0));
            }
        }
    }
    int curitem = 0;
    for (int i = 0; i <= 20000; i++) {
        while (curitem <= n && items[curitem].t <= i) curitem++;
        curitem--;
        last_avail[i] = curitem;
    }

    /*for (int i = 0; i <= 10; i++) {
        printf("%d ", last_avail[i]);
    }*/

    int q;
    scanf("%d", &q);

    for (int qry = 1; qry <= q; qry++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        int ans = 0;
        if (a < p) {
            ans = f[last_avail[a]][b];
        } else {
            if (items[last_avail[a]].t + p <= a) {
                printf("0\n"); continue;
            }
            int first_avail = last_avail[a - p] + 1;
            if (first_avail > last_avail[a]) {
                printf("0\n"); continue;
            }
            if (first_avail == last_avail[a]) {
                ans = (b >= items[first_avail].c ? items[first_avail].h : 0);
            } else if (items[first_avail].t / p == items[last_avail[a]].t / p) {
                if (items[first_avail].t / p == a / p) {
                    ans = f[last_avail[a]][b];
                } else {
                    ans = fsuf[first_avail][b];
                }
            } else {
                for (int i = 0; i <= b; i++) {
                    ans = max(ans, f[last_avail[a]][i] + fsuf[first_avail][b-i]);
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}