#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long LL;
const int NICO = 10000002;
vector<int> v;
int n, m, k, x;
LL a[NICO];
struct Num{
    int id, val;
}b[NICO/10];
bool cmp(Num x, Num y)
{
    return x.val>y.val;
} 
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        x ++;
        a[x] ++;
    }
    for(int i=1;i<NICO;i++)
    {
        a[i] = a[i-1] + a[i];
    }
    for(int i=1;i<NICO;i++)
    {
        a[i] = (LL)k * i - a[i];
        if(a[i]<0)
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i].val);
        b[i].val ++; b[i].id = i;
    }
    sort(b+1,b+1+m,cmp);
    LL minc = NICO;int pos = NICO-10;
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        minc --;
        if(minc < 0)
        {
            int ans = i - 1;
            printf("%d\n", v.size());
            for(int j=0;j<v.size();j++)
            {
                printf("%d ", v[j]);
            }
            return 0;
        }
        for(int j=pos;j>=b[i].val;j--)
        {
            if(a[j]-1 < minc) minc = a[j] - 1;
        }
        if(minc >= 0) v.push_back(b[i].id);
        pos = b[i].val;
    }
    if(minc >= 0)     
    {
        printf("%d\n", v.size());
        for(int j=0;j<v.size();j++)
        {
            printf("%d ", v[j]);
        }
    } else {
        printf("-1\n");
    }
}