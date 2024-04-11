#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int val,id,rank;
}a[100010];

int n,now,last,st,o,ans,bo;

inline int cmp1(const lhy &a,const lhy &b)
{
    if(a.val!=b.val)return a.val<b.val;
    return a.id<b.id;
}

inline int cmp2(const lhy &a,const lhy &b)
{
    return a.id<b.id;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].val),a[i].id=i;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        a[i].rank=(o+=a[i].val!=a[i-1].val);
    st=a[1].id;
    ans=0x7f7f7f7f;
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++)
        if(a[i].val==a[st].val&&a[i-1].val!=a[st].val)
        {
            if((n-i+1)%n>ans)continue;
            now=i;
            bo=1;
            last=now;
            now++;
            if(now>n)now=1;
            while(now!=i)
            {
                if(a[last].rank+1!=a[now].rank&&a[last].val!=a[now].val)
                {
                    bo=0;
                    break;
                }
                last=now;
                now++;
                if(now>n)now=1;
            }
            if(bo)ans=(n-i+1)%n;
        }
    if(ans==0x7f7f7f7f)ans=-1;
    printf("%d",ans);
}