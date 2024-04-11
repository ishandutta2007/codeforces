#include<stdio.h>
#define N 500010

int a[N], b[N], u[N], v[N], x, y, k, m, id[N], tmp, n;
double wid[N],st, en, mid, cur;
bool OK;

int main(){
    scanf("%d", &n);
    k = m = 1;
    for(int i = 0; i < n; i ++){
        scanf("%d %d", &x, &y);
        if(y > 0){ a[k] = x, u[k++] = y; }
        else{
            if(k>1 and (!tmp)) tmp = m;
            id[m] = k-1; b[m] = x; v[m++] = y;
        }
    }
    if(!tmp){ puts("-1"); return 0; }
    st = 0;
    en = 1.5 * (b[tmp] - a[id[tmp]]) / ( u[id[tmp]] - v[tmp]);
wid[0] = -2e9;
    for(int runs = 0; runs < 66; runs ++){
        mid = (st + en) / 2;
        for(int i = 1; i < k; i ++){
            wid[i] = mid * u[i] + a[i];
            if(i and wid[i] < wid[i-1]) wid[i] = wid[i-1];
        } OK = 0;
        for(int j = 1; j < m; j ++){
            cur = mid * v[j] + b[j];
            if(cur < wid[id[j]]){ OK = 1; break; }
        }
        if(OK) en = mid;
        else st = mid;
    }
    printf("%.12lf", en);
}