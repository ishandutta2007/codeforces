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
const int N = 1000005;
int n , a[N] , p[N];
LL s[N];


void work() {
    int i;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    if (s[n] % 3 != 0) {
        puts("0");
        return;
    }
    LL I = s[n] / 3;
    for (i = 1 ; i <= n ; ++ i) {
        p[i] = p[i - 1] + (s[i] == I * 2);
    }
    LL res = 0;
    for (i = 1 ; i <= n - 2 ; ++ i) {
        if (s[i] != I) continue;
        res += p[n - 1] - p[i];
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}