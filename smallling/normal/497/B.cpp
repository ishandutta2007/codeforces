#include<cstdio>
#include<algorithm>

using namespace std;

pair<int,int>Ans[100010];
int n,o,last,w1,w2,now,ans,nowcnt1,nowcnt2,nxt;
int sum1[100010],sum2[100010],where1[100010],where2[100010];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1];
        sum2[i]=sum2[i-1];
        scanf("%d",&o);
        if(o==1)sum1[i]++,where1[sum1[i]]=i;
        else sum2[i]++,where2[sum2[i]]=i;
    }
    if(o==1)
    {
        for(int i=1;i<=n;i++)
        {
            now=0;
            last=0;
            w2=w1=0;
            nowcnt1=nowcnt2=0;
            while(now<n)
            {
                nxt=where1[nowcnt1+i];
                if(!nxt)break;
                if(nxt-last-i>=i)w2++,now=where2[nowcnt2+i],nowcnt2+=i,nowcnt1=sum1[now];
                else w1++,now=nxt,nowcnt1+=i,nowcnt2=sum2[now];
                last=now;
            }
            if(now!=n||w2>=w1)continue;
            Ans[++ans]=make_pair(w1,i);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            now=0;
            last=0;
            w2=w1=0;
            nowcnt1=nowcnt2=0;
            while(now<n)
            {
                nxt=where2[nowcnt2+i];
                if(!nxt)break;
                if(nxt-last-i>=i)w1++,now=where1[nowcnt1+i],nowcnt1+=i,nowcnt2=sum2[now];
                else w2++,now=nxt,nowcnt2+=i,nowcnt1=sum1[now];
                last=now;
            }
            if(now!=n||w1>=w2)continue;
            Ans[++ans]=make_pair(w2,i);
        }        
    }
    sort(Ans+1,Ans+1+ans);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
        printf("%d %d\n",Ans[i].first,Ans[i].second);
}