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
#include <cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 300005;
int n , a[N] , b[N];

void work() {
    scanf("%d",&n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n);
    if (n == 1) {
        printf("%d\n" , a[0]);
        return;
    }
    LL ans = 0;
    for (int i = 0 ; i < n ; ++ i) {
        ans += (LL)(i + 2) * a[i];
    }
    ans -= a[n - 1];
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}