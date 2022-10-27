#include <iostream>
#include <cstdio>
using namespace std;
const int NICO = 1000002;
int n, m;
int l, r;
int res[NICO], ans;
int main()
{
    scanf("%d %d", &n, &m);
    int ml, mr, md = 10000000;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &l, &r);
        if(r - l < md)
        {
            md = r-l;
            mr=r, ml=l;
        }
    }
    ans = md + 1;
    printf("%d\n", ans);
    for(int i=ml;i<=mr;i++)
    {
        res[i] = i-ml;
    }
    for(int i=mr+1;i<=n;i++)
    {
        res[i] = (res[i-1] + 1) % (md+1);
    }
    for(int i=ml-1;i>=1;i--)
    {
        res[i] = (res[i+1] - 1 + md + 1) % (md + 1);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d", res[i]);
        if(i==n) printf("\n");
        else printf(" ");
    }
}