/*
USER_ID: icpc#finals14_084
PROBLEM: 226
SUBMISSION_TIME: 2014-03-23 14:24:18
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <cassert>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
#define N 2005
int n , p[N];
LL f[N] , Q = 1e9 + 7;

void work()
{
    int i , j;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i)
        cin >> p[i];
    LL ans = 0;
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = 1;
        for (j = p[i] ; j < i ; ++ j)
            f[i] += f[j] + 1;
        f[i] %= Q;
        ans += f[i] + 1;
        ans %= Q;
    }
    cout << ans << endl;
}


int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_--)
        work();
    return 0;
}