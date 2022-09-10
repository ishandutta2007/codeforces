#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define int ll
const int N = 1e5+7;
const int mod = 10007;

int n, ans;

int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    sort(a+1, a+1+n);

    for(int i = 1; i <= n; ++i)
    {
        ans += a[i]*a[n-i+1];
        ans %= mod;
    }

    cout << ans << endl;
}