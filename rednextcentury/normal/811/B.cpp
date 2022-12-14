#include <bits/stdc++.h>

using namespace std;
int p[100000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    while(m--)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int num=0;
        for (int i=l;i<=r;i++)
            if (p[i]<p[x])num++;
        if (num!=(x-l))
            printf("No\n");
        else printf("Yes\n");
    }
}