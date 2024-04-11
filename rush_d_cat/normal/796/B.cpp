#include <iostream>
using namespace std;
const int NICO = 1000000+10;
int n, m, k;
int h[NICO], pos = 1;
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=m;i++)
    {
        int x; scanf("%d", &x);
        h[x] = 1;
    }
    for(int i=1;i<=k;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if(h[pos] == 1)
        {
            printf("%d\n", pos);
            return 0;
        }
        if(pos == u)
        {
            pos = v;
        } else if(pos == v) {
            pos = u;
        }
    }
    printf("%d\n", pos);
}