#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define N 100005
typedef long long LL;

int A , a[N] , n , sum;
int s[N] , cnt[N];
char str[N];
void work()
{
    int i , j , l , x , y;
    LL ans = 0 , tmp = 0;
    scanf("%d%s" ,&A , str + 1);
    n = strlen(str + 1);
    for (i = 1 ; i <= n ; ++ i)
        a[i] = str[i] - '0' , sum += a[i] , s[i] = s[i - 1] + a[i];

    if (A == 0)
    {
        int s0 = 0 , s1 = 0;
            for (i = 1 , j = 0 ; i <= n ; ++ i)
            {
                x = s[i];
                //while (j <= n && s[j] < x)
                //    ++ j;
                j = lower_bound(s , s + i , x) - s;
                l = upper_bound(s , s + i , x) - s;
                s0 += max(0 , l - j);
                //if (j < i && s[j] == x) ++ s0;
            }
            for (i = 1 , j = 0; i <= n ; ++ i)
            {
                x = s[i];
                j = lower_bound(s , s + i , x) - s;
                l = upper_bound(s , s + i , x) - s;
                s1 += max(0 , l - j);
            }
        ans = (LL)(s0 + s1) * (n + 1) * n / 2;
        ans -= (LL)s0 * s1;
        cout << ans << endl;
        return;
    }

    for (int k = 1 ; k * k <= A ; ++ k)
        if (A % k == 0 && A / k <= sum && k <= sum)
        {
            int s0 = 0 , s1 = 0;
            for (i = 1 , j = 0 ; i <= n ; ++ i)
            {
                x = s[i] - k;
                j = lower_bound(s , s + i , x) - s;
                l = upper_bound(s , s + i , x) - s;
                s0 += max(0 , l - j);
            }
            for (i = 1 , j = 0; i <= n ; ++ i)
            {
                x = s[i] - (A / k);
                j = lower_bound(s , s + i , x) - s;
                l = upper_bound(s , s + i , x) - s;
                s1 += max(0 , l - j);
            }
            if (k == A / k) tmp += (LL) s0 * s1;
            else ans += (LL)s0 * s1;
        }
    cout << ans * 2 + tmp << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}