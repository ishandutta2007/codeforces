#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100005
#define M 300005

int n , a[N];

void work() {
    int i , j , k , l;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 2 ; i <= n ; ++ i)
        if (a[i] != a[i - 1])
            break;
    if (i > n) {
        puts("-1");
        return;
    }
    for (i = 1 ; i <= n ; ++ i) {
        for (j = i + 1 ; j <= n ; ++ j) {
            if (a[i] != a[j]) {
                swap(a[i] , a[j]);
                for (k = 2 ; k <= n ; ++ k)
                    if (a[k] < a[k - 1])
                        break;
                for (l = 2 ; l <= n ; ++ l)
                    if (a[l] > a[l - 1])
                        break;
                if (k <= n && l <= n) {
                    printf("%d %d\n" , i , j);
                    return;
                }
                swap(a[i] , a[j]);
            }
        }
    }
    puts("-1");
}

int main()
{
    work();
    return 0;
}