#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 1000005
int n , m , a[N] , b[N];
int p[N] , l[N] , r[N];
bool f[N];
int c[N];
set<int> s;
set<int>::iterator it;
void work()
{
    int i , j , x;
    long long ans = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , p[a[i]] = i;
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d",&x);
        f[x] = 1;
    }
    for (i = 1 ; i <= n ; ++ i)
    {
        if (f[a[i]])
        {
            it = s.upper_bound(a[i]);
            while (it != s.end())
            {
                r[*it] = i;
                s.erase(it);
                it = s.upper_bound(a[i]);
            }
        }
        else
            s.insert(a[i]);
    }
    while (s.size()) r[*s.begin()] = i , s.erase(s.begin());
    for (i = n ; i > 0 ; -- i)
    {
        if (f[a[i]])
        {
            it = s.upper_bound(a[i]);
            while (it != s.end())
            {
                l[*it] = i;
                s.erase(it);
                it = s.upper_bound(a[i]);
            }
        }
        else
            s.insert(a[i]);
    }
    while (s.size()) l[*s.begin()] = i , s.erase(s.begin());

    for (i = 1 ; i <= n ; ++ i)
        c[i] = i & -i;
    for (i = 1 ; i <= n ; ++ i)
        if (!f[i])
        {
            for (j = r[i] - 1 ; j > 0 ; j -= j & -j) ans += c[j];
            for (j = l[i] ; j > 0 ; j -= j & -j) ans -= c[j];
            for (j = p[i] ; j <= n ; j += j & -j) -- c[j];
        }
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //while (~scanf("%d",&n))
        work();
    return 0;
}