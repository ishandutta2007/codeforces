#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define wp(i,j,k,l)  (((i)*21+(j))*21+(k))*21+(l)
int n,m;char a[22][22],b[22][22];int f[250000],v[250000];
int ff()
{
    memset(f,0,sizeof f);
    memset(v,0,sizeof v);
    for(int li=0;li<20;li++)
        for(int lj=0;lj<20;lj++)
            for(int i0=1;i0<=20-li;i0++)
                for(int j0=1;j0<=20-lj;j0++)
                {
                    int i1=i0+li,j1=j0+lj,p=wp(i0,j0,i1,j1);
                    for(int i=i0;i<=i1;i++)
                        for(int j=j0;j<=j1;j++)if(b[i][j])
                        {
                            if(b[i][j]=='L')
                            {
                                v[f[wp(i0,j0,i1,j-1)]^f[wp(i0,j+1,i1,j1)]]=p;
                            }else
                            if(b[i][j]=='R')
                            {
                                v[f[wp(i0,j0,i-1,j1)]^f[wp(i+1,j0,i1,j1)]]=p;
                            }else
                            if(b[i][j]=='X')
                            {
                                v[f[wp(i0,j0,i-1,j-1)]^f[wp(i0,j+1,i-1,j1)]^f[wp(i+1,j0,i1,j-1)]^f[wp(i+1,j+1,i1,j1)]]=p;
                            }
                        }
                    for(f[p]=0;v[f[p]]==p;f[p]++);
                }
    return f[wp(1,1,20,20)];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    int S=0;
    memset(b,0,sizeof b);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i+j)&1)b[(i-j+20)/2+1][(i+j)/2+1]=a[i][j];
    S^=ff();
    memset(b,0,sizeof b);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(~(i+j)&1)b[(i-j+20)/2+1][(i+j)/2+1]=a[i][j];
    S^=ff();
    puts(S?"WIN":"LOSE");
    return 0;
}