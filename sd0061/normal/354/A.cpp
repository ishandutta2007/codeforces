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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 100005
int n , L , R , wl , wr;
int w[N];
void work()
{
    int i , j;
    scanf("%d%d%d%d%d",&n,&L,&R,&wl,&wr);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&w[i]) , w[i] += w[i - 1];
    LL ans = 1LL << 60;

    for (i = 0 ; i <= n ; ++ i)
    {
        j = n - i;
        LL s = (LL)w[i] * L + (LL)(w[n] - w[i]) * R;
        if (i == j)
        {
            ans = min(ans , s);
        }
        else if (i > j)
        {
            ans = min(ans , s + (LL) (i - j - 1) * wl);
        }
        else
        {
            ans = min(ans , s + (LL) (j - i - 1) * wr);
        }

    }
    cout << ans << endl;
}


int main()
{
    //freopen("~output.txt" , "w" , stdout);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}