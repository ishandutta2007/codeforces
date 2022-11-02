#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int v,id;
}a[2010];

int tot,last,n;

inline int cmp(const lhy &a,const lhy &b)
{
    return a.v<b.v;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].v),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        if(a[i].v==a[i-1].v)tot++;
    if(tot<2)return puts("NO"),0;
    puts("YES");
    tot=0;
    for(int i=1;i<=n;i++)
        if(a[i].v==a[i-1].v)
        {
            swap(a[i],a[i-1]);
            last=i;
            break;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].id);
    puts("");
    swap(a[last],a[last-1]);
    for(int i=last+1;i<=n;i++)
        if(a[i].v==a[i-1].v)
        {
            swap(a[i],a[i-1]);
            last=i;
            break;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].id);
    puts("");
    swap(a[last],a[last-1]);
    for(int i=1;i<=n;i++)
        if(a[i].v==a[i-1].v)
        {
            swap(a[i],a[i-1]);
            tot++;
            if(tot==2)break;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].id);
}