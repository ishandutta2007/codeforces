#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int NICO = 100000+2;
const int MOD = 1000000000 + 7;
LL n, a[NICO], cnt[NICO], po[NICO], mo[NICO];
bool chk[NICO];int prime[NICO];
void init()
{
    po[0] = 1, mo[1] = 1;
    for(int i=1;i<NICO;i++) po[i] = 2*po[i-1]%MOD;
    memset(chk, 0, sizeof(chk));
    int tot = 0;
    for(int i=2;i<NICO;i++)
    {
        if(!chk[i])
        {
            prime[tot++] = i;
            mo[i] = -1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>=NICO) break;
            chk[i*prime[j]] = 1;
            if(i%prime[j] == 0)
            {
                mo[i*prime[j]] = 0;
                break;
            } else {
                mo[i*prime[j]] = -mo[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j) continue;
            if(j*j != a[i]) cnt[a[i]/j] ++;
            cnt[j] ++;
        }
    }


}

int main()
{
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
    LL ans = 0; init();
    for(int i=1;i<NICO;i++)
    {
        ans = (ans + mo[i] * (po[cnt[i]]-1) )% MOD;
    }
    cout << (ans+1000LL*MOD)%MOD << endl;
}