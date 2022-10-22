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
#define N 400005
int n , ans[N];
pair<int , int> a[N];
void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i].first) , a[i].second = i;
    sort(a , a + n);
    for (i = 0 , j = 0 ; i < n ; ++ i)
    {
        j = max(j + 1 , a[i].first);
        ans[a[i].second] = j;
    }
    for (i = 0 ; i < n ; ++ i)
        printf("%d " , ans[i]);
}

int main()
{
 //   freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}