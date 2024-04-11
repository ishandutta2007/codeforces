#include <iostream>
using namespace std;
const int NICO = 200000 + 10;
int n, q, op, x, y;
int par[NICO], par1[NICO];
int find1(int x)
{
    if(par1[x] == -1) return x;
    return par1[x] = find1(par1[x]);
}
void unite1(int x, int y)
{
    int cx = find1(x);
    int cy = find1(y);
    if(cx != cy)
    {
        if(cx > cy) par1[cy] = cx;
        if(cx < cy) par1[cx] = cy;
    }
}
int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    unite1(x, y);
    int cx = find(x);
    int cy = find(y);
    if(cx != cy)
    {
        if(cx > cy) par[cy] = cx;
        if(cx < cy) par[cx] = cy;
    }
}
int main()
{
    scanf("%d %d", &n, &q);
    for(int i=0;i<NICO;i++)
    {
        par[i] = par1[i] = -1;
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d %d", &op, &x, &y);
        if(op == 1)
        {
            unite1(x, y);
        }
        if(op == 2)
        {
            for(int i=x;i<=y;i++)
            {
                if(find(i) != find(y)) 
                {
                    int nxt = find(i);
                    unite(i, y);
                    i = nxt;
                } else {
                    break;
                }
            }
        }
        if(op == 3)
        {
            if(find1(x) == find1(y))
            {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
}