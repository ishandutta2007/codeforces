#include <iostream>
#include <cstring>
using namespace std;
const int N = 10000+10;
const int INF = 1e7;
char s[N];
int n, x, y, cur, dpMin[N][102], dpMax[N][102];
struct Nod {
    int l, r, mid;
    int lb, rb;
    int lson, rson;
} nod[N]; int cnt = 0;

void build(int l, int r) {
    ++ cur;
    if (l == r) {
        nod[cur].l = nod[cur].r = nod[cur].mid = l;
        return;
    }
    int LB = 0, RB = 0, flag = 0;
    nod[cur].l = l, nod[cur].r = r;
    for (int i = l; i <= r; i ++) {
        if (s[i] == '(') LB ++;
        if (s[i] == ')') RB ++;  
        if (s[i] == '?' && LB - RB == 1) nod[cur].mid = i, flag = 1;
        else if (s[i] == '?' && flag == 0) nod[cur].lb ++;
        else if (s[i] == '?' && flag == 1) nod[cur].rb ++;
    }
    int mid = nod[cur].mid, c = cur;
    nod[c].lson = cur + 1;
    build(l+1, mid-1);
    nod[c].rson = cur + 1;
    build(mid+1, r-1);
}

void dp(int u, int t) {
    int l = nod[u].l, r = nod[u].r;
    int lson = nod[u].lson, rson = nod[u].rson;
    for (int i = 0; i < 101; i ++) dpMax[u][i] = -INF, dpMin[u][i] = INF;
    if (l == r) {
        dpMin[u][0] = dpMax[u][0] = s[nod[u].l] - '0';
        return;
    }  

    dp(lson, t);
    dp(rson, t);
    for (int i = 0; i < 101; i ++) if (dpMax[lson][i] != -INF)
        for (int j = 0; j + i < 101; j ++) if (dpMax[rson][j] != -INF) {
            dpMax[u][i+j+t] = max(dpMax[u][i+j+t], dpMax[lson][i]+dpMax[rson][j]);
            dpMax[u][i+j+1-t] = max(dpMax[u][i+j+1-t], dpMax[lson][i]-dpMin[rson][j]);
            dpMin[u][i+j+t] = min(dpMin[u][i+j+t], dpMin[lson][i]+dpMin[rson][j]);
            dpMin[u][i+j+1-t] = min(dpMin[u][i+j+1-t], dpMin[lson][i]-dpMax[rson][j]);   
        }
}

int main() {
    scanf("%s%d%d",s+1,&x,&y); n=strlen(s+1);    
    build(1, n);
    dp(1,x<y);
    printf("%d\n", dpMax[1][min(x,y)]);

}