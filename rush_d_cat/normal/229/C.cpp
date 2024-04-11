#include <iostream>
#include <cstdio>
using namespace std;
int n, m, x, y;
int cnt[1000000 + 10];
typedef long long ll;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &x, &y);
        cnt[x]++; cnt[y]++;
    }
    ll res = (ll)n*(n-1)*(n-2)/6;
    res -= (ll)m * (n-2);
    for(int i=1;i<=n;i++)
    {
        res += (ll)cnt[i]*(cnt[i]-1)/2;
    }
    cout << res << endl;
}