#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,ans[MAXN];
struct node
{
    int l,r,id;
}a[MAXN];
bool cmp(node x,node y)
{
    if(x.l!=y.l) return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) 
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].id=i;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++) ans[i]=2;
        int r=a[0].r;ans[a[0].id]=1;
        bool f=false;
        for(int i=1;i<n;i++)
        {
            if(a[i].l>r) {f=true; break;}
            r=max(r,a[i].r); ans[a[i].id]=1;
        }
        if(!f) puts("-1");
        else
        {
            for(int i=0;i<n;i++) printf("%d ",ans[i]);
            puts("");
        }
    }
    return 0;
}