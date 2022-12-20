#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1000004;

int d[MAXN];
int f[MAXN];
bool a[MAXN], b[MAXN];

int getF(int i){
    if(f[i] == i)
        return i;
    return f[i] = getF(f[i]);
}

int main(){
#ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    int i, j;
    scanf("%d%d", &n, &m);
    d[1] = 2;
    for(i = 1; i <= n; i++)
        f[i] = i;
    while(m--){
        scanf("%d%d", &i, &j);
        d[i]++;
        d[j]++;
        f[getF(i)] = getF(j);
    }
    for(i = 1; i <= n; i++){
        if(d[i])
            a[getF(i)] = 1;
        if(d[i]%2)
            b[getF(i)] = 1;
    }
    j = 0;
    for(i = 1; i <= n; i++)
        j += a[i];
    if(j > 1){
        j = 0;
        for(i = 1; i <= n; i++)
            if(a[i]&&!b[i])
                j++;
    }
    else
        j = 0;
    j *= 2;
    for(i = 1; i <= n; i++)
        if(d[i]%2)
            j++;
    printf("%d\n", j/2);
    return 0;
}