#include <iostream>
using namespace std;
const int NICO = 200000 + 10;
typedef long long ll;
ll a[NICO], b[NICO];
ll lowbit(int x)
{
    return x & (-x);
}
void add(int x, int add)
{
    while(x <= NICO)
    {
        a[x] += add;
        x += lowbit(x);
    }
}
ll sum(int x)
{
    ll res = 0;
    while(x!=0)
    {
        res += a[x];
        x -= lowbit(x);
    }
    return res;
}
int n;
int main()
{
    cin >> n;
    double ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        ans += (n-i+1) * (double)(sum(b[i])) / n / (n+1);
        ans -= (n-i+1) * (double)(sum(NICO)-sum(b[i])) / n / (n+1);
        add(b[i], i);  
    }
    for(int i=0;i<NICO;i++) a[i] = 0;
    for(int i=1;i<=n;i++)
    {
        ans += i - 1 - sum(b[i]);
        add(b[i], 1);
    }
    printf("%.12f\n", ans);
}