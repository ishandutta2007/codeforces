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

int n , a , b;
char str[N];
bool f[N];
bool g[N];
void work() {
    scanf("%s" , str + 1);
    scanf("%d%d",&a,&b);
    n = strlen(str + 1);
    int i , x , y;
    x = 0;
    for (i = 1 ; i < n ; ++ i) {
        x = x * 10 + str[i] - '0';
        x %= a;
        if (!x) f[i] = 1;
    }
    x = 0 , y = 1;
    for (i = n ; i > 1 ; -- i) {
        x += y * (str[i] - '0') % b , x %= b;
        if (!x && f[i - 1] && str[i] != '0') {
            x = i;
            puts("YES");
            for (i = 1 ; i < x ; ++ i)
                putchar(str[i]); puts("");
            for (i = x ; i <= n ; ++ i)
                putchar(str[i]); puts("");
            return;
        }
        y *= 10 , y %= b;
    }
    puts("NO");
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}