#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 500005;
int n;
double a[N];

void work() {
    int i , j , k;
    double ans = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%lf",&a[i]);
        ans = max(ans , a[i]);
    }
    sort(a , a + n);
    for (i = 0 ; i <n ; ++ i){
        for (j = i ; j < n ; ++ j) {
            double tmp = 1;
            for (k = i ; k <= j ; ++ k)
                tmp *= (1 - a[k]);
            double sum = 0;
            for (k = i ; k <= j; ++ k)
                sum += tmp / (1 - a[k]) * a[k];
    //        if (j == n - 1)
    //            printf("*%.15f\n" , sum);
            ans = max(ans , sum);
        }
    }
    printf("%.15f\n" , ans);
}


int main()
{
    work();
    return 0;
}