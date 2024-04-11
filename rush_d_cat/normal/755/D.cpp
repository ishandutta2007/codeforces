#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
const int NICO = 1000002;
typedef long long ll;
ll a[NICO], res[NICO];
int n, k;
int lowbit(int x)
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
int main()
{
    scanf("%d %d", &n, &k);k=min(k,n-k);
    int x = 1;res[0] = 1;
    for(int i=1;i<=n;i++)
    {
        if(x+k<=n) res[i] = res[i-1] + sum(x+k-1) - sum(x) + 1, add(x+k, 1); 
        else res[i] = res[i-1] + sum(n) - sum(x) + sum(x+k-n) + 1, add(x+k-n,1);
        add(x,1);
        x = x+k;
        if(x>n) x-=n;
    }
    printf("%I64d", res[1]);
    res[n] -= 1;
    for(int i=2;i<=n;i++)
    {
        printf(" %I64d", res[i]);
    }
}