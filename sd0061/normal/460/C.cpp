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
const int N = 100005;
int n , m , w;
int a[N] , b[N];
int f[N];
bool check(int h) {
    int i , x , y;
    for (i = 1 ; i <= n ; ++ i) {
        b[i] = max(h - a[i] , 0);
        f[i] = 0;
    }
    LL sum = 0; y = 0;
    for (i = 1 ; i <= n ; ++ i) {
        y += f[i];
        x = max(b[i] - y , 0);
        sum += x;
        f[i + 1] += x;
        if (i + w <= n)
            f[i + w] -= x;
    }
    return sum <= m;
}

void work() {
    int i , j;
    scanf("%d%d%d",&n,&m,&w);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    LL top = 1 , bot = 2e9 , mid;
    while (top < bot) {
        mid = top + bot + 1 >> 1;
        if (check(mid))
            top = mid;
        else
            bot = mid - 1;
    }
    cout << top << endl;
}

int main() {
    work();
    return 0;
}