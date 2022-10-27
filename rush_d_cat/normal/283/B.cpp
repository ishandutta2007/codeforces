#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;
typedef __int64 ll;
const ll M = 2e5 + 10;
ll p[M][2], val[M], n;
ll dfs(ll x, ll tmp) //tmpx~
{
        if(x > n || x <= 0) return 0;
        if(p[x][tmp]) return p[x][tmp];
        p[x][tmp]=-1;
        ll ret = dfs((tmp?val[x]:-val[x])+x, 1-tmp);
        return ret==-1?p[x][tmp]=-1:p[x][tmp]=ret+val[x];
}
int main()
{
        cin>> n;
        for(int i=2;i<=n;i++) scanf("%I64d", &val[i]);
        for(int i=1;i<n;i++)
        {
                val[1]=i;p[1][0]=p[1][1]=0;
                printf("%I64d\n", dfs(1,1));
        }
}