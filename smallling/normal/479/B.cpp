#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int x,id;
}a[1000];

struct lnm{
    int x,y;
}ans[10000];

int n,k,tot;

inline int cmp(const lhy &a,const lhy &b)
{
    return a.x<b.x;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    while(a[n].x-a[1].x>1&&tot<k)
    {
        a[n].x--;
        a[1].x++;
        ans[++tot]=(lnm){a[n].id,a[1].id};
        sort(a+1,a+1+n,cmp);
    }
    printf("%d %d\n",a[n].x-a[1].x,tot);
    for(int i=1;i<=tot;i++)
        printf("%d %d\n",ans[i].x,ans[i].y);
}