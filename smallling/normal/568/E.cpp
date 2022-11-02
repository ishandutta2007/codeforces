#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,len,l,r,mid,now,last,cnt;
int a[100010],b[100010],c[100010];
int f[100010],Max[100010],pre[100010],flag[100010];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=0x7f7f7f7f;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    b[m+1]=0x7f7f7f7f;
    sort(b+1,b+1+m);
    c[1]=0x7f7f7f7f;
    len=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=-1)
        {
            l=1;r=len+1;now=0;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(c[mid]>=a[i])r=mid-1;
                else now=mid,l=mid+1;
            }
            if(now==len)len++,c[len+1]=0x7f7f7f7f;
            c[now+1]=a[i];
            f[i]=now+1;
            Max[now+1]=i;
            pre[i]=Max[now];
        }
        else
        {
            pre[i]=-1;f[i]=-1;
            int l=len;
            for(int j=m;j;j--)
            {
                while(c[l]>=b[j])--l;
                if(l==len)++len;
                c[l+1]=b[j],Max[l+1]=i;
            }
            c[len+1]=0x7f7f7f7f;
        }
    now=last=n+1;
    f[n+1]=len+1;
    pre[n+1]=Max[len];
    cnt=m+1;
    b[0]=-1;
    for(int i=len;i>=0;i--)
        if(f[pre[now]]!=-1)now=pre[now],last=now;
        else
            if(f[now]-i>1)
            {
                while(b[cnt]==b[cnt-1])cnt--;cnt--;
                while(b[cnt]>=a[now])cnt--;
                while(a[last]!=-1)last--;
                a[last]=b[cnt],flag[cnt]=1;
                last--;
                for(int j=last;j>=0;j--)
                    if(f[j]==i&&a[j]<b[cnt])
                    {
                        last=now=j;
                        break;
                    }
            }
    cnt=1;
    for(int i=1;i<=n;i++)
        if(a[i]==-1)
        {
            while(flag[cnt])cnt++;
            a[i]=b[cnt++];
        }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
}