#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define W 91
ll a[W];bool v[W];ll f[W][3*3];
int main()
{
    a[0]=1,a[1]=2;for(int i=2;i<W;i++)a[i]=a[i-1]+a[i-2];
    int _;scanf("%d",&_);
    while(_--)
    {
        ll n;scanf("%I64d",&n);
        memset(v,0,sizeof v);
        for(int i=W-1;i>=0;i--)
            if(n>=a[i])n-=a[i],v[i]=1;
        memset(f,0,sizeof f);
        f[W-1][0]=1;
        for(int i=W-1;i;i--)
            for(int j=0;j<9;j++)if(f[i][j])
            {
                int x0=j/3,x1=j-x0*3;
                for(int k=0;k<=x1;k++)
                {
                    if(x1-k>=2)continue;
                    int y0=v[i-1]+k,y1=x0+k;
                    if(y1>2||y0>2)continue;
                    f[i-1][y0*3+y1]+=f[i][j];
                }
            }
        ll S=0;
        for(int j=0;j<9;j++)
        {
            int x0=j/3,x1=j-x0*3;
            if(x0<2&&x1<2)S+=f[0][j];
        }
        printf("%I64d\n",S);
    }
    return 0;
}