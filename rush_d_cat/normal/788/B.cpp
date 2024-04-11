#include <iostream>
#include <set>
using namespace std;
const int NICO = 2000000 + 10;
typedef long long LL;
set<int> st;
int n, m, u, v, x;
int par[NICO], cnt[NICO], gg[NICO], deg[NICO];
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    int cx = find(x);
    int cy = find(y);
    if(cx != cy)
    {
        par[cx] = cy;
    }
}
int main()
{
    for(int i=0;i<NICO;i++)
    {
        par[i] = -1;
    }
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &u, &v);
        st.insert(u);st.insert(v);
        if(u == v)
        {
            gg[u] = 1; x++;
        } else {
            deg[u] ++, deg[v] ++;
        }
        unite(u, v);
    }
    int ok = 0;
    for(int i=1;i<=n;i++)
    {
        int x = find(i);
        cnt[x] ++;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i] == st.size())
        {
            ok = 1;
        }
    }
    if(ok == 0)
    {
        cout << 0 << endl;
    } else {
        LL ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(deg[i] >= 2)
            {
                ans += (LL)deg[i]*(LL)(deg[i]-1)/2;
            }
        }
        ans += (LL)x * (LL)(m-x);
        ans += (LL)x * (LL)(x-1) / 2;
        cout << ans << endl;
    }
}