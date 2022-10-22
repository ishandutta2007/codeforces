#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , L , a[N];

void work() {
    int i ;
    scanf("%d%d",&n,&L);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&a[i]);
    }
    sort(a , a + n);
    int ans = 2 * max(a[0] , L - a[n - 1]);
    for (i = 1 ; i < n ; ++ i) {
        ans = max(ans , a[i] - a[i - 1]);
    }
    printf("%.10f\n" , ans / 2.0);
}

int main() {
    work();
    return 0;
}