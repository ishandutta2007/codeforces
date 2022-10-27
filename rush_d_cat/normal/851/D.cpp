#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cmath>
using namespace std;
#define N 2000000+10

typedef long long LL;
int n, x, y;
int a[N], cnt[N];
LL sum[N];

LL cac1(int L, int R)
{
    LL count = cnt[R] - cnt[L - 1];
    LL sigma = sum[R] - sum[L - 1];
    LL ans = count * R - sigma;
    return (LL)ans * (LL)y;
}

LL cac2(int L, int R)
{
    return (LL)(cnt[R] - cnt[L-1]) * (LL)x;
}

int main()
{
    scanf("%d %d %d", &n, &x, &y);

    int mx = 0;

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        cnt[ a[i] ] ++;
        sum[ a[i] ] += a[i];
    }


    for (int i = 1; i < N; i ++)
    {
        cnt[i] = cnt[i - 1] + cnt[i];
        sum[i] = sum[i - 1] + sum[i];
    }

    LL ans = 1e18;
    LL num = (x + y - 1) / y;

    for (int i = 2; i < N; i ++)
    {
        LL temp = 0;

        for (int j = i; j < N; j += i)
        {
            if (i < num) {
                temp += cac1(j - i + 1, j);
            } else {
                int k = j - num; 
                temp += cac1(k + 1, j);
                temp += cac2(j - i + 1, k);
            }
        }
        //if(i <= 20)
        //printf("%d %lld\n", i, temp);
        ans = min(ans, temp);
    }

    cout << ans << endl;

}