# include <iostream>
# include <string>
#include <cstdio>
#include <iomanip>
#include <queue>
# include <stack>
#include <ios>
using namespace std;
long long num;
long long ans;
long long n;
long long m;
long long g;
bool check(long long k)
{
    long long l = 0;
    for (int i = 1; i <= n; i++)
    {
        l += min(k / i, m);
    }
    if (l>=g)
        return 1;
    else
        return 0;
}
void binsearch(long long s, long long e)
{
    while (s <= e)
    {
        long long mid = (s + e) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
}
int main()
{
        cin >> n >> m>>g;
        num = n*m;
        ans = n*m + 1;
        binsearch(1, n*m);
        cout << ans << endl;
}