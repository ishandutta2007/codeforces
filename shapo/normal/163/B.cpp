#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 100500
#define maxit 100

using namespace std;

struct lem{int m, v, id;};

int n, k, h;
int used[maxn];
int res[maxn];
lem sm[maxn];
double l, r;

bool cmp(const lem &a, const lem &b){return(a.m > b.m || a.m == b.m && a.v > b.v || a.m == b.m && a.v == b.v && a.id < b.id);}

bool ok(const double &x){
    int cur = 0, num = k;
    while(cur < n && num > 0){
        if(x >= double(num * h) / double(sm[cur].v)){
            used[num] = sm[cur].id;
            --num;
        }
        ++cur;
    }
    return(num == 0);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &h);
    for(int i = 0; i < n; ++i)scanf("%d", &sm[i].m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &sm[i].v);
        sm[i].id = i;
    }
    sort(sm, sm + n, cmp);

    double r = 0;
    for(int i = 0; i < n; ++i)r = max(r, double(n * h) / double(sm[i].v) + double(100));
    for(int i = 0; i < maxit; ++i){
        double m = (l + r) / 2;
        if(ok(m))r = m; else l = m;
    }

    ok(r);
    //printf("%.10lf\n", (l + r) / 2);
    for(int i = 1; i <= k; ++i)printf("%d ", used[i] + 1);
    printf("\n");

    return 0;
}