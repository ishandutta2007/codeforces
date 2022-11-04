#include <cstdio>
#include <iostream>
#include <cmath>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 1, L = 21;

int lg2[N] = {0, 0}, n, m, q, a[N][L], sx, sy, tx, ty, k;

int query(int l, int r){
    int len = r - l + 1;
    return max(a[l][lg2[len]], a[r - (1 << lg2[len]) + 1][lg2[len]]);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= m; i++)
        lg2[i] = lowbit(i) == i ? lg2[i - 1] + 1 : lg2[i - 1];
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i][0]);
    for (int j = 1; j < L; j++)
        for (int i = 1; i + (1 << j) - 1 <= m; i++)
            a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d%d%d", &sx, &sy, &tx, &ty, &k);
        if(sy > ty){
            swap(sx, tx);
            swap(sy, ty);
        }
        if((ty - sy) % k != 0 || abs(sx - tx) % k != 0){
            puts("NO");
            continue;
        }
        int h = (n - sx) / k * k + sx;
        puts(query(sy, ty) < h ? "YES" : "NO");
    }
    return 0;
}