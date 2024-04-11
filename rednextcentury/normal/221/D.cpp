#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
    int id,ans;
};
int SQRT=330;

bool comp(node a, node b)
{
    if (a.l/SQRT == b.l/SQRT)
        return a.r<b.r;
    else
        return a.l/SQRT < b.l/SQRT;
}
bool comp1(node a,node b)
{
    return a.id<b.id;
}
node q[1000300];
int a[1000300];
int vis[1000300];
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<m;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q,q+m,comp);
    int L=1,R=1;
    int ans=0;
    if (a[1]<1000000)
    {
    vis[a[1]]=1;
    if (a[1]==1)ans++;
    }
    for (int i=0;i<m;i++)
    {
        while(L<q[i].l)
        {
            if (a[L]<1000000)
            {
                vis[a[L]]--;
                if (vis[a[L]]==a[L])ans++;
                if (vis[a[L]]==a[L]-1)ans--;
            }
            L++;
        }
        while(L>q[i].l)
        {
            L--;
            if (a[L]<1000000)
            {
                vis[a[L]]++;
                if (vis[a[L]]==a[L])ans++;
                if (vis[a[L]]==a[L]+1)ans--;
            }
        }
        while(R<q[i].r)
        {
            R++;
            if (a[R]<1000000)
            {
                vis[a[R]]++;
                if (vis[a[R]]==a[R])ans++;
                if (vis[a[R]]==a[R]+1)ans--;
            }
        }
        while(R>q[i].r)
        {
            if (a[R]<1000000)
            {
                vis[a[R]]--;
                if (vis[a[R]]==a[R])ans++;
                if (vis[a[R]]==a[R]-1)ans--;
            }
            R--;
        }
        q[i].ans=ans;
    }
    sort(q,q+m,comp1);
    for (int i=0;i<m;i++)
        printf("%d\n",q[i].ans);
}