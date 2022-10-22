#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , a[N];
int res[N];

void work() {
    int i , j , k , x , y;

    
    scanf("%d" , &n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (i = 2 ; i <= n ; ++ i) {
        j = i - 2;
        for (k = 1 ;  ; k = x + 1) {
            y = j / k;
            if (y == 0) {
                if (a[i] < a[y + 1])
                    ++ res[k];
                break;
            } else {
                x = j / y;
                if (a[i] < a[y + 1])
                    res[k] ++ , res[x + 1] --;
            }
        }        
    }
    for (i = 1 ; i < n ; ++ i) {
        res[i] += res[i - 1];
        printf("%d%c" , res[i] , " \n"[i + 1 == n]);
    }
}

int main() {
    work();
    return 0;
}