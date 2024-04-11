#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int a[maxn];
int pre[maxn];
int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++)
        pre[i]=i;
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==a[i-1])
        {
            int u = Find(i);
            int v = Find(i-1);
            if (u!=v)
                pre[u]=v;
        }
    }
    for (int i = 1;i<=m;i++)
    {
        int flag = 0;
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int temp = r;
        while (l<=temp)
        {
            if (a[temp]!=x)
            {
                printf("%d\n",temp);
                flag=1;
                break;
            }
            temp = Find(temp)-1;
        }
        if (flag==0)
            printf("-1\n");
    }
}