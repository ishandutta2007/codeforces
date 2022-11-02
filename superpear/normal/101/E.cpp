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
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int kuai=200;

int n,m,bigp,x,y,k1,k2,o,findc,qq,l,r;
int data1[20001],data2[20001],which[202],f[2][20001],a[202][20001];
short g[202][20001];
char ch[50000];

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d %d %d",&n,&m,&bigp);
    for (int i=0;i<n;i++) scanf("%d",&data1[i]);
    for (int i=0;i<m;i++) scanf("%d",&data2[i]);
    f[0][0]=(data1[0]+data2[0])%bigp;
    o=0;
    for (int i=0;i<m+n-2;i++)
    {
        k1=i%2;k2=(i+1)%2;
        l=max(0,i-m);r=min(i,n-1);
        for (int j=l;j<=r;j++)
        {
            x=j;y=i-j;
            if (f[k1][j]+(data1[x+1]+data2[y])%bigp>f[k2][j+1])
                f[k2][j+1]=f[k1][j]+(data1[x+1]+data2[y])%bigp;
            if (f[k1][j]+(data1[x]+data2[y+1])%bigp>f[k2][j])
                f[k2][j]=f[k1][j]+(data1[x]+data2[y+1])%bigp;
        }
        if (i%kuai==0)
        {
            ++o;which[o]=i;
            for (int j=0;j<n;j++) a[o][j]=f[k1][j];
        }
    }
    cout<<f[k2][n-1]<<endl;
    //return 0;
    ++o;which[o]=m+n-2;
    findc=n-1;
    for (int tt=o-1;tt>=1;tt--)
    {
        memset(g,0,sizeof(g));
        //1 for Candy 2 for stone
        n=findc+1;
        for (int i=0;i<n;i++) f[which[tt]%2][i]=a[tt][i];
        for (int i=which[tt];i<which[tt+1];i++)
        {
            k1=i%2;k2=(i+1)%2;
            for (int j=0;j<n;j++) f[k2][j]=-1;
            l=max(0,i-m);r=min(i,n-1);
            for (int j=l;j<=r;j++)
            {
                if (f[k1][j]==-1) continue;
                x=j;y=i-j;
                if (f[k1][j]+(data1[x+1]+data2[y])%bigp>f[k2][j+1])
                {
                    f[k2][j+1]=f[k1][j]+(data1[x+1]+data2[y])%bigp;
                    g[i+1-which[tt]][j+1]=1;
                }
                if (f[k1][j]+(data1[x]+data2[y+1])%bigp>f[k2][j])
                {
                    f[k2][j]=f[k1][j]+(data1[x]+data2[y+1])%bigp;
                    g[i+1-which[tt]][j]=2;
                }
            }
        }
        for (int i=which[tt+1];i>which[tt];i--)
        {
            if (g[i-which[tt]][findc]==1)
            {
                --findc;
                ++qq;ch[qq]='C';
            }
            else
            {
                ++qq;ch[qq]='S';
            }
        }
    }
    for (int i=qq;i>=1;i--) putchar(ch[i]);putchar('\n');

    return 0;
}