#include <bits/stdc++.h>
using namespace std;
const int N = 5000005;
int s[N] , p[N] , tot;
bool f[N];
int main() {
    int i , j , x;
    for (i = 2 ; i < N ; ++ i) {
        if (!f[i])
            p[tot ++] = i ;
        for (j = 0 ; j < tot ; ++ j) {
            x = i * p[j];
            if (x >= N) break;
            f[x] = 1 ;
            if (i % p[j] == 0) 
                break;          
        }
    }
    for (i = 1 ; i < N ; ++ i) {
        s[i] = s[i - 1] , x = i;
        for (j = 0 ; p[j] * p[j] <= x ; ++ j)
            while (x % p[j] == 0)
                x /= p[j] , ++ s[i];
        s[i] += x > 1;
    }
    scanf("%d" , &x);
    while (x --) {
        scanf("%d%d" , &i , &j);
        printf("%d\n" , s[i] - s[j]);
    }
    return 0;
}