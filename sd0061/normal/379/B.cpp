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
int n , a[N];
char ans[1000005] ;
int t;
void work()
{
    int i , j;
    cin >> n;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    int x = i;
    if (a[0]) ans[t ++] = 'P' , -- a[0];

    for (j = 1 ; j <= 305 ; ++ j)
    {
        for (i = 1 ; i < n ; ++ i)
        {
            ans[t ++] = 'R';
            if (a[i])
                ans[t ++] = 'P' , -- a[i];
        }
        for (i = n - 2 ; i >= 0 ; -- i)
        {
            ans[t ++] = 'L';
            if (a[i])
                ans[t ++] = 'P' , -- a[i];
        }
    }
    printf("%s" , ans);


}

int main()
{
 //   freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}