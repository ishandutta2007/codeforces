#include<cstdio>

using namespace std;

long long ans;
int n,q,now,nowk,cnt,nowsum,x,sum,Cnt,nowans;
int a[200020],A[500020],flag[500020],Sum[500020];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)
    {
        A[0]=0;
        scanf("%d",&x);
        if(flag[x])flag[x]=0,nowk=-1,Cnt--;
        else flag[x]=1,nowk=1,Cnt++;
        if(a[x]==1&&flag[x])
        {
            ans+=Cnt-1;
            printf("%I64d\n",ans);
            continue;
        }
        if(a[x]==1&&!flag[x])
        {
            ans-=Cnt;
            printf("%I64d\n",ans);
            continue;
        }
        now=a[x];
        for(int j=2;j*j<=now;j++)
            if(now%j==0)
            {
                while(now%j==0)now/=j;
                A[++A[0]]=j;
            }
        if(now!=1)A[++A[0]]=now;
        sum=1<<A[0];
        nowans=0;
        if(nowk==1)
        {
            for(int now=1;now<sum;now++)
            {
                cnt=0;nowsum=1;
                for(int x1=1;x1<=A[0];x1++)
                    if(now&(1<<(x1-1)))cnt++,nowsum*=A[x1];
                if(cnt&1)nowans+=Sum[nowsum];
                else nowans-=Sum[nowsum];
            }
            for(int now=1;now<sum;now++)
            {
                cnt=0;nowsum=1;
                for(int x1=1;x1<=A[0];x1++)
                    if(now&(1<<(x1-1)))cnt++,nowsum*=A[x1];
                Sum[nowsum]+=nowk;
            }
        }
        else
        {
            for(int now=1;now<sum;now++)
            {
                cnt=0;nowsum=1;
                for(int x1=1;x1<=A[0];x1++)
                    if(now&(1<<(x1-1)))cnt++,nowsum*=A[x1];
                Sum[nowsum]+=nowk;
            }
            for(int now=1;now<sum;now++)
            {
                cnt=0;nowsum=1;
                for(int x1=1;x1<=A[0];x1++)
                    if(now&(1<<(x1-1)))cnt++,nowsum*=A[x1];
                if(cnt&1)nowans+=Sum[nowsum];
                else nowans-=Sum[nowsum];
            }
        }
        ans+=1ll*nowk*(Cnt-nowans-(flag[x]==1));
        printf("%I64d\n",ans);
    }
}