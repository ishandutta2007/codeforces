#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int num,id,o;
}a[100001];

int n,m;

int cmp(lhy a,lhy b)
{
    return a.num<b.num;
}

int cmp1(lhy a,lhy b)
{
    return a.id<b.id;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].num),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        a[i].o=i%2;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i].o);
}