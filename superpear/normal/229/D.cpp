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
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

int n,k,t,rc,fc,a[10000],sum[10000],f[5005][5005],u[10000];

int main()
{
    //freopen("D2.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    memset(f,127,sizeof(f));
    for (int i=1;i<=n;i++)
        f[1][i]=sum[i];
    for (int i=2;i<=n;i++)
    {
        k=1;
        while ((k<n)&&(f[i-1][k]==biglongint)) ++k;
        memset(u,0,sizeof(u));
        rc=1;fc=1;u[rc]=k;
        for (int j=1;j<=n;j++)
        {
            while ((rc<fc)&&(u[rc+1]<j)&&(sum[j]-sum[u[rc+1]]>=f[i-1][u[rc+1]])) ++rc;
            //if (i==5) cout<<u[rc]<<" "<<u[rc+1]<<endl;
            k=u[rc];
            if ((k<j)&&(sum[j]-sum[k]>=f[i-1][k])) f[i][j]=sum[j]-sum[k];
            if (f[i-1][j]==biglongint) continue;
            while ((fc>=rc)&&(f[i-1][j]+sum[j]-sum[u[fc]]<=f[i-1][u[fc]])) --fc;
            ++fc;u[fc]=j;
        }
        //cout<<endl;
    }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            if (f[i][j]==biglongint) cout<<"-1  "; else cout<<f[i][j]<<"  ";
        cout<<endl;
    }*/
    for (int i=n;i>=1;i--)
        if (f[i][n]!=biglongint)
        {
            cout<<n-i<<endl;
            return 0;
        }

    return 0;
}