#include <cstdio>
#include <iostream>
#include <cmath>
#define x1 x1_
#define y1 y1_
#define x2 x2_
#define y2 y2_
using namespace std;
const int N = 1e5 + 1, L = 21;

int n, m, xtmp, y[N], x[N], ytmp, x1, y1, l1, x2, y2, l2;
long long tt[N][L], tr[N][L], rt[N][L], rr[N][L];

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        scanf("%d%d%d%d", &xtmp, &y[i], &x[i], &ytmp);
    x[n] = x[n - 1], y[n] = y[n - 1];
    for (int i = 1; i < n; i++){
        tt[i][0] = abs(x[i] - x[i + 1]) + 1;
        rr[i][0] = abs(y[i] - y[i + 1]) + 1;
        tr[i][0] = 1 + i + 1 - x[i] + i + 1 - y[i + 1];
        rt[i][0] = 1 + i + 1 - y[i] + i + 1 - x[i + 1];
    }
    for (int j = 1; j < L; j++)
        for (int i = 1; i + (1 << (j - 1)) < n; i++){
            tt[i][j] = min(tt[i][j - 1] + tt[i + (1 << (j - 1))][j - 1], tr[i][j - 1] + rt[i + (1 << (j - 1))][j - 1]);
            rr[i][j] = min(rr[i][j - 1] + rr[i + (1 << (j - 1))][j - 1], rt[i][j - 1] + tr[i + (1 << (j - 1))][j - 1]);
            rt[i][j] = min(rr[i][j - 1] + rt[i + (1 << (j - 1))][j - 1], rt[i][j - 1] + tt[i + (1 << (j - 1))][j - 1]);
            tr[i][j] = min(tt[i][j - 1] + tr[i + (1 << (j - 1))][j - 1], tr[i][j - 1] + rr[i + (1 << (j - 1))][j - 1]);
        }
    scanf("%d", &m);
    while(m--){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        l1 = max(x1, y1);
        l2 = max(x2, y2);
        if(l1 == l2){
            printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
            continue;
        }
        if(l1 > l2){
            swap(x1, x2);
            swap(y1, y2);
            swap(l1, l2);
        }
        long long t = abs(x1 - x[l1]) + abs(y1 - l1);
        long long r = abs(x1 - l1) + abs(y1 - y[l1]);
        int diff = l2 - l1 - 1;
        for (int j = 0; (1 << j) <= diff; j++)
            if((1 << j) & diff){
                long long _t = min(t + tt[l1][j], r + rt[l1][j]);
                long long _r = min(r + rr[l1][j], t + tr[l1][j]);
                t = _t, r = _r;
                l1 += 1 << j;
            }
        t++, r++;
        // printf("x1 %d y1 %d x2 %d y2 %d t %d r %d l2 %d x[l2 - 1] %d\n", x1, y1, x2, y2, t, r, l2, x[l2 - 1]);
        printf("%lld\n", min(t + abs(x[l2 - 1] - x2) + abs(l2 - y2), r + abs(l2 - x2) + abs(y[l2 - 1] - y2)));
    }
    return 0;
}