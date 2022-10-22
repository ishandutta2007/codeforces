#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , m ;
int a[N];
void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    int ans = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        ans += min(a[x] , a[y]);
    }
    printf("%d\n" , ans);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);

    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}