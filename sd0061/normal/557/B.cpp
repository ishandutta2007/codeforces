#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , w , a[N << 1];
int main() {
    scanf("%d%d" , &n , &w);
    for (int i = 0 ; i < n + n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a , a + n + n);
    double res = *min_element(a , a + n);
    res = min(res , *min_element(a + n , a + n + n) * 0.5);
    res = min(res , w / 3.0 / n);
    printf("%.10f\n" , 3 * n * res);
    return 0;
}