#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 4005
int n , m;
pair<int , int> a[N];
int f[N] , mnp[N] , mnm[N] , mxp[N] , mxm[N];
vector< pair< int , pair<int , int> > > e;
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
int main()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n + m ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second) , f[i] = i;
    for (i = 1 ; i <= n + m ; ++ i)
        for (j = i + 1 ; j <= n + m ; ++ j)
            if (i <= n && j <= n && a[i].first + a[i].second == a[j].first + a[j].second)
            {
                x = (abs(a[i].first - a[j].first)) + 1 / 2;
                e.push_back(make_pair(x , make_pair(i , j)));
            }
            else if (i > n && j > n && a[i].first - a[i].second == a[j].first - a[j].second)
            {
                x = (abs(a[i].first - a[j].first)) + 1 / 2;
                e.push_back(make_pair(x , make_pair(i , j)));
            }
            else if (i <= n && j > n)
            {
                x = max((abs(a[j].first + a[j].second - a[i].first - a[i].second) + 1) / 2 ,
                        (abs(a[j].first - a[j].second - a[i].first + a[i].second) + 1) / 2 );
                e.push_back(make_pair(x , make_pair(i , j)));
            }
    sort(e.begin() , e.end());
    for (i = 1 ; i <= n ; ++ i)
        mxm[i] = -1 << 30 , mnm[i] = 1 << 30 , mxp[i] = mnp[i] = a[i].first + a[i].second;
    for (i = n + 1 ; i <= n + m ; ++ i)
        mxm[i] = mnm[i] = a[i].first - a[i].second , mxp[i] = -1 << 30 , mnp[i] = 1 << 30;

    for (i = 0 ; i < (int)e.size() ; ++ i)
    {
        x = e[i].second.first , y = e[i].second.second;
        x = getf(x) , y = getf(y);
        if (x == y && mxm[x] != mnm[x] && mnp[x] != mxp[x])
        {
            printf("%d\n" , e[i].first);
            return 0;
        }
        else
        {
            mxm[y] = max(mxm[y] , mxm[x]);
            mxp[y] = max(mxp[y] , mxp[x]);
            mnp[y] = min(mnp[y] , mnp[x]);
            mnm[y] = min(mnm[y] , mnm[x]);
            f[getf(x)] = getf(y);
        }
    }
    puts("Poor Sereja!");
    return 0;
}