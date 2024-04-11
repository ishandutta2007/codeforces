#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define N 5005
int n , m;
int a[N] , b[N];
set<int> bad;
bool f[32005];
int p[32005] , tot;
int cnt[N] , w[N];
void work()
{
    int i , j , x;
    int ans = 0;
    for (i = 2 ; i <= 180 ; ++ i) if (!f[i])
        for (j = i * i ; j <= 32000 ; j += i)
            f[j] = 1;
    for (i = 2 ; i <= 32000 ; ++ i) if (!f[i])
        p[tot ++] = i;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
    }
    for (j = 1 ; j <= m ; ++ j) {
        scanf("%d",&b[j]);
        bad.insert(b[j]);
    }
    cnt[1] = a[1];
    for (j = 2 ; j <= n ; ++ j)
        cnt[j] = __gcd(a[j] , cnt[j - 1]);
    //cout << tot << endl;
    for (i = 1 ; i <= n ; ++ i) {
        x = a[i];
        for (j = 0 ; j < tot && p[j] <= x ; ++ j)
            while (x % p[j] == 0)
            {
                x /= p[j];
                ans += bad.count(p[j]) ? -1 : 1;
            }
        if (x > 1)
            ans += bad.count(x) ? -1 : 1;
    }
    //cout << ans << endl;
    for (i = 1 ; i <= n ; ++ i) {
        x = cnt[i];
        for (j = 0 ; j < tot && p[j] <= x ; ++ j)
            while (x % p[j] == 0)
            {
                x /= p[j];
                w[i] += bad.count(p[j]) ? -1 : 1;
            }
        if (x > 1)
            w[i] += bad.count(x) ? -1 : 1;
    }
    for (i = n ; i > 0 ; -- i )
        if (w[i] < 0) {
            ans -= w[i] * i;
            for (j = 1 ; j <= i ; ++ j)
                w[j] -= w[i];
        }
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}