#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define N 100005
typedef long long LL;
int n , m , f[N] , p , q , num , cnt[N];
LL s[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work()
{
    int i ,j , x , y ,z;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    num = n;
    for (i = 1 ; i <= n ; ++ i) f[i] = i , cnt[i] = 1;
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d%d",&x , &y , &z);
        int xx = getf(x) , yy = getf(y);
        if (xx != yy)
        {
            f[xx] = yy;
            cnt[yy] += cnt[xx];
            s[yy] += s[xx] + z;
            num --;
        }
        else s[yy] += z;
    }

    if (num < q || num - q > p)
        puts("NO");
    else
    {
        vector< pair<int , int> > ans;
        set< pair<LL , int> > h;
        for (i = 1 ; i <= n ; ++ i)
            if (getf(i) == i)
                h.insert(make_pair(s[i] , i));
        while (p && num > q)
        {
            p -- , num --;
            pair<LL , int> A = *h.begin();
            h.erase(h.begin());
            pair<LL , int> B = *h.begin();
            h.erase(h.begin());
            LL w = min(1000000000LL , A.first + B.first + 1);
            ans.push_back(make_pair(A.second , B.second));
            f[A.second] = B.second;
            cnt[B.second] += cnt[A.second];
            s[B.second] += A.first + w;
            h.insert(make_pair(s[B.second] , B.second));
        }
        if (!p)
        {
            puts("YES");
            for (i = 0 ; i < ans.size() ; ++ i)
                printf("%d %d\n" , ans[i].first , ans[i].second);
            return;
        }

        for (i = 1 ; i <= n ; ++ i)
            if (getf(i) == i && cnt[i] > 1)
                break;
        if (i > n)
        {
            puts("NO");
            return;
        }
        x = i;
        for (i = 1 ; i <= n ; ++ i)
            if (getf(i) == x && i != x)
                break;
        y = i;
        puts("YES");
        for (i = 0 ; i < ans.size() ; ++ i)
            printf("%d %d\n" , ans[i].first , ans[i].second);
        while (p --)
            printf("%d %d\n" , x , y);

    }



}

int main()
{
   // freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}