#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l,r;
    int id;
    long long ans;
};
int SQRT=447;

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
    vis[a[1]]=1;
    long long ans=a[1];
    for (int i=0;i<m;i++)
    {
        while(L<q[i].l)
        {
            ans-=(2*vis[a[L]]-1)*a[L];
            vis[a[L]]--;
            L++;
        }
        while(L>q[i].l)
        {
            L--;
            ans+=(2*vis[a[L]]+1)*1LL*a[L];
            vis[a[L]]++;
        }
        while(R<q[i].r)
        {
            R++;
            ans+=(2*vis[a[R]]+1)*1LL*a[R];
            vis[a[R]]++;
        }
        while(R>q[i].r)
        {
            ans-=(2*vis[a[R]]-1)*1LL*a[R];
            vis[a[R]]--;
            R--;
        }
        q[i].ans=ans;
    }
    sort(q,q+m,comp1);
    for (int i=0;i<m;i++)
        printf("%I64d\n",q[i].ans);
}