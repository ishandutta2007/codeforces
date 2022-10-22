#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 200005
using namespace std;
typedef long long LL;
int n , m , w[N] , a[N] , k;
/*int p[100][100];
int dfs(int k , int pre)
{
    if (k == n)
    {
        int i , j;
        for (i = 0 ; i < m ; ++ i)
        {
            for (j = i + 1 ; j < m ; ++ j)
                if (!p[i][j])
                    break;
            if (j < m) break;
        }
        if (i >= m) return 1;
        return 0;
    }
    for (int i = 0 ; i < m ; ++ i)
    {
      //  if (k && p[pre][i]) continue;
        if (k) ++ p[pre][i] , ++ p[i][pre];
        a[k] = i;
        if (dfs(k + 1 , i)) return 1;
        if (k) -- p[pre][i] , -- p[i][pre];
    }
    return 0;
}

void test()
{
    memset(p , 0 ,sizeof(p));
    cin >> n >> m;
    cout << dfs(0 , -1) << endl;
    for (int i = 0 ; i < n ; ++ i)
        printf("%d " , a[i]);
        puts("");
}*/


void work()
{
    int i , x;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d",&x , &w[i]);
    sort(w , w + m , greater<int>());
    for (i = 1 ; i <= 10000 ; ++ i)
        if (i & 1)
            a[i] = i * (i - 1) / 2 + 1;
        else 
            a[i] = i * i / 2;
    k = i - 1;
    for (i = 1 ; i <= k ; ++ i)
        if (a[i] <= n && a[i + 1] > n)
            break;
    m = min(i , m);
    LL ans = 0;
    for (i = 0 ; i < m ; ++ i) ans += w[i];
    cout << ans <<endl;
}


int main()
{
  //  freopen("~input.txt" , "r" , stdin);
   //while(1)
    //test();
        work();
    return 0;
}