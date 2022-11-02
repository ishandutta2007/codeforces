#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int n, int num)
{
    int ans = 0;
    while (n)
    {
        ans += n / num;
        n /= num;
    }
    return ans;
}

signed main()
{
    int n, d;
    cin >> n >> d;
    int ans = 2 * 1e18;
    for (int i = 2; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            int need = 0;
            while (d % i == 0)
            {
                need++;
                d /= i;
            }
            int cnt_have = get(n, i);
            ans = min(ans, cnt_have / need);
        }
    }
    if (d != 1)
    {
        int need = 1;
        int cnt_have = get(n, d);
        ans = min(ans, cnt_have / need);
    }
    cout << ans;
    return 0;
}