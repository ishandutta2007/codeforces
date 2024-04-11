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
int k , X , n , m;
LL f[55], g[55], h[55];

void work()
{
    cin >> k >> X >> n >> m;
    for (int s1 = 0; s1 <= n / 2; ++ s1)
    for (int s2 = 0; s2 <= m / 2; ++ s2)
    {
        for (int a = 0 ; a < 2; ++ a)
        for (int b = 0 ; b < 2; ++ b)
        for (int c = 0 ; c < 2; ++ c)
        for (int d = 0 ; d < 2; ++ d)
        {
            if (s1 + s1 + a + b <= n && s2 + s2 + c + d <= m)
            {
                f[1] = s1, g[1] = a, h[1] = b;
                f[2] = s2, g[2] = c, h[2] = d;
                for (int i = 3; i <= k; ++ i)
                {
                    f[i] = f[i - 2] + f[i - 1];
                    if (h[i - 2] && g[i - 1])   f[i] ++;
                    g[i] = g[i - 2];
                    h[i] = h[i - 1];
                    if (f[i] > X)
                    {
                        f[k] = X + 1;
                        break;
                    }
                }
                if (f[k] == X)
                {
                    if (a)  printf("C");
                    for (int i = 1; i <= s1; ++ i)  printf("AC");
                    for (int i = 1; i <= n - s1 - s1 - a - b; ++ i) printf("M");
                    if (b)  printf("A");
                    printf("\n");

                    if (c)  printf("C");
                    for (int i = 1; i <= s2; ++ i)  printf("AC");
                    for (int i = 1; i <= m - s2 - s2 - c - d; ++ i) printf("M");
                    if (d)  printf("A");
                    printf("\n");
                    return;
                }
            }
        }
    }
    printf("Happy new year!\n");
}

int main()
{
 //   freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}