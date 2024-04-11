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
const int N = 1000005;

int n;
int B[N] , F[N] , a[N];
bool f[N];

void work() {
    int i , x , y;
    scanf("%d",&n);
    memset(B , -1 , sizeof(B));
    memset(F , -1 , sizeof(F));
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&y);
        F[y] = x , B[x] = y;
        f[x] = f[y] = 1;
    }
    i = 2 , x = B[0];
    while (i <= n) {
        a[i] = x;
        x = B[x];
        i += 2;
    }
    for (i = 1 ; i <= 1000000 ; ++ i)
        if (!~F[i] && f[i])
            break;
    x = i , i = 1;
    while (i <= n) {
        a[i] = x;
        x = B[x];
        i += 2;
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d " , a[i]);
}

int main() {
    work();
    return 0;
}