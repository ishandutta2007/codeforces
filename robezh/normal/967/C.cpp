#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;
const int INF = (int)2e9;

int n,m,cl,ce,v,q;
int sta[MAXN], ele[MAXN];
int xa, ya, xb, yb;

int getwiths(int s){
    return abs(xa - xb) + abs(ya - s) + abs(yb - s);
}

int getwithe(int e){
    return (abs(xa - xb)+(v-1))/v + abs(ya - e) + abs(yb - e);
}

int main() {
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    for(int i = 0; i < cl; i++) scanf("%d", &sta[i]);
    for(int i = 0; i < ce; i++) scanf("%d", &ele[i]);
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        if(xa == xb){
            printf("%d\n", abs(ya - yb));
            continue;
        }
        int res = INF;
        if(ya > yb){
            int tmp = ya; ya = yb; yb = tmp;
        }

        int as = int(lower_bound(sta, sta+cl, ya) - sta);
        if(as < cl) res = min(res, getwiths(sta[as]));
        if(as-1 >= 0) res = min(res, getwiths(sta[as-1]));
        int ae = int(lower_bound(ele, ele+ce, ya) - ele);
        if(ae < ce) res = min(res, getwithe(ele[ae]));
        if(ae-1 >= 0) res = min(res, getwithe(ele[ae-1]));

        printf("%d\n", res);
    }
}