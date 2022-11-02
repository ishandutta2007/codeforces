#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int x,y;
}a[100010];

int n,ans;

inline int cmp(const lhy &a,const lhy &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    ans=a[1].y;
    for(int i=2;i<=n;i++)
        if(a[i].y<ans)ans=a[i].x;
        else ans=a[i].y;
    printf("%d",ans);
}