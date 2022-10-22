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
#define N 100005

int n , c;
double s , ans;

void work()
{
    int i; double x;
    scanf("%d",&n);
    for (i = 1 ; i <= n + n ; ++ i)
    {
        scanf("%lf",&x);
        if (floor(x) == ceil(x))
            ++ c;
        else s += x - floor(x);
    }
    ans = 1e60;
    for (i = max(n - c , 0) ; i <= n ; ++ i)
        ans = min(ans , fabs(s - i));
    printf("%.3f\n" , ans + 1e-7);
}

int main()
{
    work();
    return 0;
}