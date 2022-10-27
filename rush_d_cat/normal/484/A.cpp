#include <iostream>
using namespace std;
typedef __int64 ll;
int n;
ll l, r;
ll a[70];
ll pow(int i)
{
    if(i == 0) return 1;
    return pow(i - 1) * (ll)2;
}
ll solve(ll l, ll r)
{
    int i;
    if(l == 0 && r == 0) return 0;
    ll ans = 0, tmp = 0;
    bool flag = 0;
    for(i = 1; i <= 61; i++)
    {
        if(a[i] < l && a[i + 1] > l)
        {
            tmp = a[i] + 1;
        }
        if(l <= a[i] && a[i] <= r)
        {
            flag = 1;
            ans = a[i];
        }
    }
    if(!flag)
    {
        ans = solve(l - tmp, r - tmp) + tmp;
    }
    return ans;
}
int main()
{
    int i;
    cin >> n;

    for(i = 1; i <= 61; i++)
        a[i] = pow(i) - 1;

    for(i = 1; i <= n; i++)
    {
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    return 0;
}