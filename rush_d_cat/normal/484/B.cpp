#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000000 + 2;
int a[3 * maxn], b[3 * maxn];
int main()
{
    int n, i, j, num; cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> num;
        a[num] = num;
        b[num] = num;
    }
    for(i = 1; i <= 2 * maxn; i++)
    {
        a[i] = max(a[i], a[i - 1]);
    }
    int res = 0;
    for(i = 1; i <= maxn; i++)
    {
        if(b[i])
        {
            for(j = 2 * b[i] - 1; j <= 2 * maxn; j += b[i])
            {
                res = max(res ,a[j] % b[i]);
            }
        }
    }
    cout << res << endl;
    return 0;
}