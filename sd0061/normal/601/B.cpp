#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , K;    
int a[N] , b[N] , L[N] , R[N];
int s[N] , top;
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n; ++ i)
        scanf("%d" , &a[i]);
    while (m --) {
        int l , r;
        scanf("%d%d" , &l , &r);
        int K = r - l;
        for (int i = 0 ; i < K ; ++ i) {
            b[i] = abs(a[l + i] - a[l + i + 1]);
            //printf("%d\n" , b[i]);
        }
        LL res = 0;
        top = 0;
        for (int i = 0 ; i < K ; ++ i) {
            while (top && b[s[top - 1]] <= b[i]) {
                R[s[-- top]] = i; 
            }
            s[top ++] = i; 
        }
        while (top)
            R[s[-- top]] = K;
        for (int i = K - 1 ; i >= 0 ; -- i) {
            while (top && b[s[top - 1]] < b[i]) {
                L[s[-- top]] = i; 
            }
            s[top ++] = i; 
        }
        while (top)
            L[s[-- top]] = -1;
        for (int i = 0 ; i < K ; ++ i) {
            //printf("%d %d %d\n" , b[i] , L[i] , R[i]);
            res += (LL)b[i] * (i - L[i]) * (R[i] - i);
        }
        printf("%lld\n" , res);
    }
}

int main() {
    work();
    return 0;
}