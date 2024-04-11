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
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , a[N] , b[N];
int f[N];
void work() {
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (i = 0 ; i + 1 < n ; ++ i) {
        a[i] = a[i + 1] - a[i];
    }
    if (n == 1)
        a[0] = 0;
    -- n;
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d" , &b[i]);
    }
    for (i = 0 ; i + 1 < m ; ++ i) {
        b[i] = b[i + 1] - b[i];
    }
    if (m == 1)
        b[0] = 0;
    -- m;
    if (m == 0) {
        printf("%d\n" , n + 1);
        return;
    }
    if (n == 0) {
        puts("0");
        return;
    }
    f[0] = f[1] = 0;
    for (i = 1 ; i < m ; ++ i) {
        int j = f[i];
        while (j && b[i] != b[j])
            j = f[j];
        f[i + 1] = b[i] == b[j] ? j + 1 : 0;
    }
    int res = 0;
    for (i = 0 , j = 0 ; i < n ; ++ i) {
        while (j && a[i] != b[j])
            j = f[j];
        if (a[i] == b[j])
            ++ j;
        if (j == m)
            ++ res;
    }
    cout << res << endl;
}


int main() {
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}