#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1 << 20;
int m , n;
LL t , Q;
void FWT(LL a[] , int len , int oper) {
    for (int k = 0 ; 1 << k < len ; ++ k) {
        for (int i = 0 ; i < len ; ++ i) {
            if (~i >> k & 1) {
                int j = i ^ (1 << k);
                LL x = (a[i] + Q - a[j]) % Q;
                LL y = (a[i] + a[j]) % Q;
                if (oper == -1) {
                    x = (Q - x) % Q;
                    swap(x , y);
                }
                a[i] = x;
                a[j] = y;
            }
        }
    }
}
LL mul(LL a , LL b){
    return (a * b - (LL) ((long double)a * b / Q) * Q) % Q;
}
int b[25];
LL f[N] , res[N];
int work() {
    scanf("%d%lld%lld" , &m , &t , &Q);
    n = 1 << m , Q *= n;
    for (int i = 0 ; i < n ; ++ i)
        scanf("%lld" , &res[i]);
    for (int i = 0 ; i <= m ; ++ i)
        scanf("%d" , &b[i]);
    for (int i = 0 ; i < n ; ++ i)
        f[i] = b[__builtin_popcount(i)];

    FWT(res , n , 1);
    FWT(f , n , 1);
    while (t) {
        if (t & 1) {
            for (int j = 0 ; j < n ; ++ j) {
                res[j] = mul(res[j] , f[j]);
            }
        }
        for (int j = 0 ; j < n ; ++ j) 
            f[j] = mul(f[j] , f[j]);
        t >>= 1;
    }
    FWT(res , n , -1);
    for (int i = 0 ; i < n ; ++ i)
        printf("%d\n" , (int)(res[i] / n));
}

int main() {
    work();
    return 0;
}