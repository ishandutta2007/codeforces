#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 1e9
#define maxn 70005
#define mod 100007

using namespace std;

vector <int> h[mod];

int n,m,a[maxn][50],t,s,ans[maxn],d[maxn*9],p[maxn],cnt[maxn*9],lst[maxn*9];

void put_in(int x,int y)
{
    t++;
    d[t]=x;
    cnt[t]=1;
    lst[t]=y;
    h[x%mod].push_back(t);
}

int find_(int x)
{
    int tt=x%mod;
    for (int i=0;i<h[tt].size();i++)
        if (d[h[tt][i]]==x) return h[tt][i];
    return 0;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&t);s=0;
        for (int j=1;j<=9;j++)
        {
            a[i][++s]=t%10;
            t/=10;
        }
        for (int k=2;k<=9;k++)
            for (int j=1;k+j<=10;j++)
            {
                s++;
                a[i][s]=a[i][s-10+k]*10+a[i][j];
            }
    }
    s=1;
    memset(ans,-1,sizeof(ans));
    for (int i=1;i<=9;i++){
        t=0;
        memset(cnt,0,sizeof(cnt));
        memset(lst,0,sizeof(lst));
        for (int j=0;j<mod;j++) h[j].clear();
        for (int j=1;j<=n;j++)
            for (int k=s;k<s+10-i;k++)
            {
                int ss=find_(a[j][k]);
                //if (i==2) printf("%d\n",a[j][k]);
                if (!ss) put_in(a[j][k],j);
                else if (lst[ss]!=j) cnt[ss]++,lst[ss]=j;
            }
                //if (!find_(a[j][k])) put_in(a[j][k]);

        for (int j=1;j<=n;j++)
            for (int k=s;k<s+10-i;k++){
            if (ans[j]==-1&&cnt[find_(a[j][k])]==1){
                p[j]=i;
                ans[j]=a[j][k];
            }
        }

        s+=(10-i);
    }
    //for (int i=1;i<=n;i++) printf("%d\n",p[i]);
    //system("pause");
    for (int i=1;i<=n;i++)
    {
        t=ans[i];
        do{
            p[i]--;
            t/=10;
        }while (t);
        for (int j=0;j<p[i];j++) printf("0");
        printf("%d\n",ans[i]);
    }
    return 0;
}