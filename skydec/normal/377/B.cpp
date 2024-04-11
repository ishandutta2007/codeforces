#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAXN 110000
using namespace std;
long temp[MAXN];bool flag=false;long anstemp[MAXN];
long n,m,s;
struct node
{
    long num,cost,can;
}stu[MAXN];
struct things
{
    long num,cost;
}thing[MAXN];
bool cmpth(things a,things b){return a.cost<b.cost;}
bool cmpstu(node a,node b){return a.can<b.can;}
long fa[MAXN],l[MAXN],r[MAXN];
long root=0;
void init()
{
    root=0;
    memset(fa,0,sizeof fa);
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
}
long merge(long a,long b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(stu[a].cost>stu[b].cost){long tmp=a;a=b;b=tmp;}
    long sk=merge(r[a],b);
    r[a]=sk;fa[sk]=a;
    long tmp=l[a];l[a]=r[a];r[a]=tmp;
    return a;
}
void del()
{
    fa[l[root]]=fa[r[root]]=0;
    root=merge(l[root],r[root]);
}
bool check(long d)
{
    long p=m;long q=n-1;long long use=0;root=n;
    while(p&&!(q==0&&root==0))
    {
        while(stu[q].can>=thing[p].cost&&q>=1)
        {
            root=merge(root,q);q--;
        }
        if(root==0)break;
        long j=stu[root].can;use+=(long long)stu[root].cost;if(use>s)return false;
        long y=d;
        while(y--)
        {
            if(p==0)break;
            if(thing[p].cost<=j)
            {
                anstemp[thing[p].num]=stu[root].num;
                p--;
            }
            else break;
        }
        del();
    }
    if(p!=0)return false;
    if(use>s)return false;
    for(long i=1;i<=m;i++)temp[i]=anstemp[i];
    flag=true;
    return true;
}
int main()
{
    scanf("%ld%ld%ld",&n,&m,&s);
    for(long i=1;i<=m;i++)
    {
        scanf("%ld",&thing[i].cost);
        thing[i].num=i;
    }
    for(long i=1;i<=n;i++)
    {
        scanf("%ld",&stu[i].can);
        stu[i].num=i;
    }
    for(long i=1;i<=n;i++)scanf("%ld",&stu[i].cost);
    long l=1;long r=m;sort(thing+1,thing+1+m,cmpth);sort(stu+1,stu+1+n,cmpstu);
    while(l<r)
    {
        init();
        long mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid+1;
    }
    init();check(l);
    if(flag)
    {
        printf("YES\n");
        for(long i=1;i<=m;i++)printf("%ld ",temp[i]);
    }
    else printf("NO\n");
    return 0;
}