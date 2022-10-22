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

const int N = 100005;
int n , k;

int main() {
    scanf("%d%d",&n,&k);
    int x = 1 , y = n , i = 1;
    while (k) {
        -- k;
        if (i & 1)
            printf("%d " , x ++);
        else
            printf("%d " , y --);
        i ^= 1;
    }
    if (i) {
        while (y >= x)
            printf("%d " , y --);
    } else {
        while (y >= x)
            printf("%d " , x ++);
    }
    return 0;
}