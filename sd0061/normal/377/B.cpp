#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
#define N 100005
int n , D , m , S , ans[N];
pair<int , pair<int , int> > a[N];
pair<int , int> v[N];
bool f[N];

struct opt
{
    int x , w;
    bool operator < (const opt& r) const
    {
        return w > r.w;
    }
};
priority_queue<opt> Q;

/*LL check(int day)
{
    int i , j , x , y; LL sum = 0;
    memset(f , 0 , sizeof(f));
    for (i = m ; i > 0 ; i -= day)
    {
        x = v[i].first , y = -1;
        for (j = 1 ; j <= n ; ++ j) if (!f[j] && a[j].first >= x)
            if (!~y || a[j].second.fi < a[y].second.fi)
                y = j;
        f[y] = 1 , sum += a[y].second.fi;
        for (j = max(1 , i - day + 1) ; j <= i ; ++ j)
            ans[v[j].second] = a[y].se.se;
    }
    return sum;
}*/

LL check(int day)
{
    int i , j , k , x , y; LL sum = 0;
    while (!Q.empty()) Q.pop();
    for (i = m , k = n ; i > 0 ; i -= day)
    {
        x = v[i].first;
        while (k > 0 && a[k].first >= x)
            Q.push((opt){k , a[k].se.fi}) , -- k;
        if (Q.empty()) return 1LL << 60;
        y = Q.top().x , Q.pop();

        //for (j = 1 ; j <= n ; ++ j) if (!f[j] && a[j].first >= x)
        //    if (!~y || a[j].second.fi < a[y].second.fi)
        //        y = j;
        sum += a[y].second.fi;
        for (j = max(1 , i - day + 1) ; j <= i ; ++ j)
            ans[v[j].second] = a[y].se.se;
    }
    return sum;
}

void work()
{
    int i , j , x;
    scanf("%d%d%d",&n,&m,&S);
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d",&v[i].first) , v[i].second = i;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i].first);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i].second.fi) , a[i].se.se = i;
    sort(v + 1 , v + 1 + m);
    sort(a + 1 , a + 1 + n);
    if (v[m].first > a[n].first)
    {
        puts("NO");
        return;
    }
    int top = 1 , bot = m , mid;
    while (top < bot)
    {
        mid = top + bot >> 1;
        if (check(mid) <= S)
            bot = mid;
        else top = mid + 1;
    }
    if (check(top) > S)
    {
        puts("NO");
        return;
    }
    puts("YES");
    for (i = 1 ; i <= m ; ++ i)
        printf("%d " , ans[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}