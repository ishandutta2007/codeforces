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

const int bigp=1000000007;

long long n;
int m,k,x1,x2,ls,sum,a[60][60],f[75][60][60],ans[60],ans2[60];
char ch1,ch2,ch;

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=1;
    scanf("%c",&ch);
    for (int i=1;i<=k;i++)
    {
        scanf("%c%c%c",&ch1,&ch2,&ch);
        if ((ch1>='a')&&(ch1<='z')) x1=ch1-96; else x1=ch1-64+26;
        if ((ch2>='a')&&(ch2<='z')) x2=ch2-96; else x2=ch2-64+26;
        a[x1][x2]=0;
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
            f[0][i][j]=a[i][j];
    for (int ic=1;ic<=70;ic++)
    {
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=m;k++)
                    f[ic][i][j]=(f[ic][i][j]+((long long)f[ic-1][i][k])*f[ic-1][k][j])%bigp;
    }
    for (int i=1;i<=m;i++) ans[i]=1;
    --n;
    ls=0;
    while (n>0)
    {
        if (n%2==1)
        {
            memset(ans2,0,sizeof(ans2));
            for (int i=1;i<=m;i++)
                for (int j=1;j<=m;j++)
                    ans2[j]=(ans2[j]+((long long)ans[i])*f[ls][i][j])%bigp;
            for (int i=1;i<=m;i++) ans[i]=ans2[i];
        }
        ++ls;n/=2;
    }
    sum=0;
    for (int i=1;i<=m;i++) sum=(sum+ans[i])%bigp;
    cout<<sum<<endl;

    return 0;
}