#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int m,n,e,flag,last,sum,ans,dat[105][10005],f[105][10005];
char ch;

int main()
{
    scanf("%d %d",&m,&n);
    scanf("%c",&ch);
    for (int i=1;i<=m;i++)
    {
        flag=1;
        for (int j=1;j<=n;j++)
        {
            scanf("%c",&ch);
            dat[i][j]=ch-48;
            if (dat[i][j]==1) flag=0;
        }
        scanf("%c",&ch);
        if (flag==1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    for (int i=1;i<=m;i++)
    {
        last=-1;
        for (int j=1;j<=n;j++)
        {
            if (dat[i][j]==1) last=j;
            if (last!=-1) f[i][j]=j-last; else f[i][j]=maxlongint;
        }
        last=-1;
        for (int j=n;j>=1;j--)
        {
            if (dat[i][j]==1) last=j;
            if (last!=-1) f[i][j]=min(f[i][j],last-j);
        }
        e=0;
        for (int j=1;j<=n;j++)
        {
            if (dat[i][j]==1) {e=j;break;}
        }
        for (int j=e+1;j<=n;j++)
            f[i][j]=min(f[i][j],n-j+e);
        e=0;
        for (int j=n;j>=1;j--)
        {
            if (dat[i][j]==1) {e=j;break;}
        }
        for (int j=1;j<e;j++)
            f[i][j]=min(f[i][j],n-e+j);
    }
    ans=maxlongint;
    for (int i=1;i<=n;i++)
    {
        sum=0;
        for (int j=1;j<=m;j++)
            sum+=f[j][i];
        ans=min(ans,sum);
    }
    cout<<ans<<endl;

    return 0;
}