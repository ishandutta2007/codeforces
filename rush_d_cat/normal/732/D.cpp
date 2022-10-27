#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 100000 + 10;
typedef long long ll;
int n, m, d[MAXN], a[MAXN] ,used[MAXN];
bool ok(int k)
{
    int res = k-1, i, need = 0;
    memset(used,0,sizeof(used));
    for(i = k; i >= 1; i--)
    {
        if(d[i] > 0 && !used[d[i]])
        {
            if(res < a[d[i]]) return 0;
            res -= a[d[i]];
            need += a[d[i]];
            used[d[i]] = 1;
        } else {
            if(need == 0) res--;
            else need --;
        }
    }
    if(need) return 0;
    int o = 1;
    for(i = 1; i <= m; i++)
    {
        if(!used[i]) o = 0;
    }
    return o;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%d", &d[i]);
    for(int i=1;i<=m;i++) scanf("%d", &a[i]);
    if(!ok(n)) cout<<-1<<endl;
    else{
        int l=1, r=n;
        while(r-l>1)
        {
            int mid = (l+r)/2;
            if(ok(mid))
            {
                r = mid;
            } else {
                l = mid;
            }
        }
        if(ok(r-1)) cout<<(r-1)<<endl;
        else cout<<r<<endl;
    }
}