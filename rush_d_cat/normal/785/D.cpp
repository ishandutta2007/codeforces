#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10;
const int P = 1000000007;
char s[NICO];
int pre[NICO], suf[NICO];
LL f[1000001], v[1000001];
LL rp(LL now, int k) 
{
    LL will = 1;
    for (; k; k >>= 1, now *= now, now %= P) 
    {
        if (k & 1) will *= now, will %= P;
    }
    return will;
}
LL C(int n, int m) 
{
    if(n < m) return 0;
    return f[n] * rp(f[m], P - 2) % P * rp(f[n - m], P - 2) % P;
}
void init()
{
    f[0] = 1; v[0] = 1;
    for (int i = 1; i <= 1000000; i++) //1e6
    {
        f[i] = f[i - 1] * i % P;
    }
}


int main()
{
    init();
    scanf("%s" ,s+1);
    int n = strlen(s+1);
    
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '(')
        {
            pre[i] = pre[i-1] + 1;
        } else {
            pre[i] = pre[i-1];
        }
    }

    for(int i=n;i>=1;i--)
    {
        if(s[i] == ')')
        {
            suf[i] = suf[i+1] + 1;
        } else {
            suf[i] = suf[i+1];
        }
    }
    LL ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '(')
        {
            ans += C(pre[i]+suf[i]-1, suf[i]-1);
            ans %= P;
        }
    }
    cout << ans << endl; 
}