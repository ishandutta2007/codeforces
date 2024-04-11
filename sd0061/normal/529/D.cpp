#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , T;
int t[N] , res[N] , K;
int c[N];

void work() {
    int i , j , k; bool f = 0;
    scanf("%d%d%d",&n,&m,&T);
    for (i = 0 ; i < n ; ++ i) {
        int A , B , C;
        scanf("%d:%d:%d" ,&A , &B, &C);
        t[i] = A * 3600 + B * 60 + C + 1;
    }
    for (i = 0 ; i < n ; ++ i) {
        int x = 0;
        for (j = t[i] ; j > 0 ; j -= j & -j)
            x += c[j];
        if (x < m) {
            res[i] = ++ K;
            for (j = t[i] ; j <= 86400 ; j += j & -j)
                c[j] ++;
            for (j = t[i] + T ; j <= 86400 ; j += j & -j)
                c[j] --;
            if (x + 1 == m)
                f = 1;
        } else {
            res[i] = K;
            for (j = t[i - 1] + T ; j <= 86400 ; j += j & -j)
                c[j] ++;
            for (j = t[i] + T ; j <= 86400 ; j += j & -j)
                c[j] --;                        
        }
    }
    if (!f)
        puts("No solution");
    else {
        printf("%d\n" , K);
        for (i = 0 ; i < n ; ++ i)
            printf("%d\n" , res[i]);
    }
}

int main () {
    work();
    return 0;
}