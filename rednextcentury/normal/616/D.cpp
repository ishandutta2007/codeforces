#include <bits/stdc++.h>

using namespace std;
int vis[1000001];
int s,e;
int a[1000001];
int n,k;
bool check(int l)
{
    for(int i=0;i<n;i++)
        vis[a[i]]=0;
    int num=0;
    for (int i=0;i<l;i++)
    {
        if (++vis[a[i]]==1)
            num++;
    }
    if (num<=k)
    {
        s=1,e=l;
        return 1;
    }
    for (int i=l;i<n;i++)
    {
        if (--vis[a[i-l]]==0)
            num--;
        if (++vis[a[i]]==1)
            num++;
        if (num<=k)
        {
            s=i-l+2;
            e=i+1;
            return 1;
        }
    }
    return 0;
}
void binsearch(int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
}
int main()
{
   scanf("%d%d",&n,&k);
   for (int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   binsearch(1,n);
   printf("%d %d\n",s,e);
}