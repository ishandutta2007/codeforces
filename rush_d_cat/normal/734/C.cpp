#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int NICO = 200000+2;
ll n, k, m;
ll x, s;
ll a[NICO], b[NICO], c[NICO], d[NICO];
ll res = 4 * 1e18;
int find(int x)
{
    if(x < 0) return 0;
    int l = 1, r = k;
    while(r - l > 1)
    {
        int mid = (l+r) / 2;
        if(d[mid] < x)
        {
            l = mid;
        } else {
            r = mid;
        }
    }
    while(l <= k && d[l] <= x)
    {
        l++;
    }
    l --;
    return l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> x >> s;
    res = n * x;
    d[0] = 0;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        if(b[i] <= s)
        {
            res = min(res, a[i]*n);
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin >> d[i];   
        if(d[i] <= s)
        {
            res = min(res, x*(n-c[i]));
        }
    }
    for(int i=1;i<=m;i++)
    {
        int pos = find(s - b[i]);
        if(pos == 0) continue;
        res = min(res, (n-c[pos]) * a[i]);
    }
    cout << res << endl;
}