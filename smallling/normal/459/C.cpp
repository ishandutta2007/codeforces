#include<cstdio>

using namespace std;

int n,k,d,bo,now,cnt,a[100010],ans[1010][1010];

int main()
{
    scanf("%d%d%d",&n,&k,&d);
    now=1;
    for(int i=1;i<=d;i++)
    {
        now*=k;
        if(now>=n)
        {
            bo=1;
            break;
        }
    }
    if(!bo)
    {
        puts("-1");
        return 0;
    }
    cnt=0;
    while(cnt<n)
    {
        if(a[d]==k)
        {
            now=d;
            while(now&&a[now]==k)a[now]=0,a[now-1]++,now--;
        }
        cnt++;
        for(int i=1;i<=d;i++)
            ans[cnt][i]=a[i];
        a[d]++;
    }
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",ans[j][i]+1);
        putchar('\n');
    }
}