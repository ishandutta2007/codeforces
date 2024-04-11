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
int n , m , a[N] , b[N];
char str[N];

void work() {
    int i , x , y;
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    y = x = 0;
    for (i = 1 ; i <= n ; ++ i) {
        if (str[i] == '(')
            ++ y;
        if (str[i] == ')')
            -- y;
        if (str[i] == '#') {
            a[++ m] = 1;
            x = i;
            -- y;
        }
    }
    if (y < 0) {
        puts("-1");
    } else {
        if (y && !m) {
            puts("-1");
        } else {
            a[m] += y;
            y = x = 0;
            for (i = 1 ; i <= n ; ++ i) {
                if (str[i] == '(')
                    ++ y;
                if (str[i] == ')')
                    -- y;
                if (str[i] == '#') {
                    y -= a[++ x];
                }
                if (y < 0) {
                    puts("-1");
                    return;
                }
            }
            for (i = 1 ; i <= m ; ++ i)
                printf("%d\n" , a[i]);
        }
    }
}

int main() {
    work();
    return 0;
}