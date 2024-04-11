#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/MTACK:16777216")
using namespace std;
typedef long long LL;
const int N = 1000005;
const int M = 20;
int n , cnt[1 << M] , f[1 << M];
bool rev[1 << M];
int power[N] , Q = 1e9 + 7;
void work() {
    int i , j , x;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&x) , ++ cnt[x];
    power[0] = 1;
    for (i = 1 ; i <= n ; ++ i)
        power[i] = (power[i - 1] << 1) % Q;
    rev[0] = 0;
    for (i = 1 ; i < 1 << M ; ++ i)
        rev[i] = !rev[i & (i - 1)];
    int ans = 0;
    for (i = 0 ; i < M ; ++ i)
        for (j = 0 ; j < 1 << M ; ++ j)
            if (~j >> i & 1)
                cnt[j] += cnt[j | 1 << i];
    for (i = 0 ; i < 1 << M ; ++ i) {
        if (rev[i])
            ans += (Q - power[cnt[i]]) , ans %= Q;
        else
            ans += power[cnt[i]] , ans %= Q;
    }
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}