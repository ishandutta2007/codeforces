#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll e[200005], w[200005], n, x, k, z = 1, a[200005], mx = 0;
int main()
{
    cin >> n >> k >> x;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0,j=n-1;i < n; i++,j--)
    {
        if (j != n - 1)
            e[j] = (e[j + 1] | a[j]);
        else
            e[j] = a[j];
        if (i != 0)
            w[i] = (w[i - 1] | a[i]);
        else
            w[i] = a[i];
    }
    for (ll i = 0; i < k; i++)
        z *= x;
    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
                mx = ((a[i] * z) | e[i + 1]);
         else if (i == n - 1)
        {
            if (((a[i] * z) | (w[i - 1])) > mx)
                mx = ((a[i] * z) | w[i - 1]);
            continue;
        }
        else if (((a[i] * z) | w[i - 1] | e[i + 1]) > mx)
            mx =((a[i] * z) | w[i - 1] | e[i + 1]);
    }
    cout << mx << endl;
    return 0;
}