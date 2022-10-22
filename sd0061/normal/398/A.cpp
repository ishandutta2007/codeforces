#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 2005
int A , B;
LL ans , sum;
void work()
{
    int i , j , x , y ;
    cin >> A >> B;
    if (A == 0)
    {
        printf("%I64d\n" , (LL) -B * B);
        for (i = 0 ; i < B ; ++ i)
            putchar('x');
        return;
    }
    ans = -1LL << 60;
    for (i = 1 ; i <= A ; ++ i)
    {
        sum = 0;
        sum += (LL) (A - i + 1) * (A - i + 1);
        sum += i - 1;
        j = i + 1;
        x = B / j , y = B % j;
        sum -= (LL) y * (x + 1) * (x + 1);
        sum -= (LL) (j - y) * x * x;
        ans = max(ans , sum);
    }
    printf("%I64d\n" , ans);
    for (i = 1 ; i <= A ; ++ i)
    {
        sum = 0;
        sum += (LL) (A - i + 1) * (A - i + 1);
        sum += i - 1;
        j = i + 1;
        x = B / j , y = B % j;
        sum -= (LL) y * (x + 1) * (x + 1);
        sum -= (LL) (j - y) * x * x;
        if (sum == ans)
        {
            for (j = 0 ; j <= i + i ; ++ j)
                if (~j & 1)
                    for (int k = 0 ; k < x + (j / 2 < y) ; ++ k)
                        putchar('x');
                else
                    for (int k = 0 ; k < (j == 1 ? A - i + 1 : 1) ; ++ k)
                        putchar('o');
            break;
        }
    }

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}