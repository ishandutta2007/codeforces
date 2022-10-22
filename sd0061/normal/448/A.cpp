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
#include <cctype>
using namespace std;
typedef long long LL;

int a[3] , b[3] , n;

int main() {
    int i;
    for (i = 0 ; i < 3 ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < 3 ; ++ i)
        scanf("%d",&b[i]);
    scanf("%d",&n);
    if ((a[0] + a[1] + a[2] + 4) / 5 + (b[0] + b[1] + b[2] + 9) / 10 <= n)
        puts("YES");
    else
        puts("NO");
    return 0;
}