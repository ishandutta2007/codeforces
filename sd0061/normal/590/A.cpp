#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
typedef long long LL;
const int N = 500005;
using namespace std;

int n , a[N] , b[N];

void cal(int l , int r) {
    int len = r - l + 1;
    if (len & 1) {
        for (int i = l ; i <= r ; ++ i)
            b[i] = a[l];
    } else {
        for (int i = l ; i <= r ; ++ i) {
            if (i - l < len / 2)
                b[i] = a[l];
            else
                b[i] = !a[l];                                
        }
    }
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]);
    int res = 0;
    int x = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (i == n || a[i] == a[i - 1]) {
            // [x , i - 1]
            res = max(res , (i - x - 1) / 2);
            cal(x , i - 1);
            x = i;
        }
    }
    printf("%d\n" , res);
    for (int i = 0 ; i < n ; ++ i)
        printf("%d%c" , b[i] , " \n"[i + 1 == n]);
    return 0;   
}