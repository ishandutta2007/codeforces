#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n , k , m , p , w = 1e9;
int a[N];
void work()
{
    cin >> n >> k;
    if (!k) {
        if (n < 2) {
            puts("1");
        } else
            puts("-1");
        return;
    }
    if (n == 1) {
        puts("-1");
        return;
    }
    p = n;
    if (n & 1)
        a[n] = w -- , -- n;
    while (n >= 4 && k > 0) {
        a[++ m] = w --;
        a[++ m] = w --;
        n -= 2;
        -- k;
    }
    if (n && k == 0) {
        puts("-1");
        return;
    }
    a[++ m] = k;
    a[++ m] = k + k;
    for (int i = 1 ; i <= p ; ++ i)
        printf("%d\n" , a[i]);
}


int main()
{
    //freopen("~inputs.txt" , "r" , stdin);
    work();
    return 0;
}