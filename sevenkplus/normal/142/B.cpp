#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[12]={-2,-2,-1,-1,1,1,2,2},dy[12]={-1,1,-2,2,-2,2,-1,1};
int n,m,t0,t1,a[1010][1010],b[500010][12],l[500010],c[500010],S,B[500010],L=0;bool v[500010];
bool ff(int x)
{
    if(v[x])return 0;v[x]=1;B[L++]=x;
    for(int i=0;i<l[x];i++)
        if(c[b[x][i]]==-1||ff(c[b[x][i]]))
        {
            c[b[x][i]]=x;return 1;
        }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    if(n==1||m==1)printf("%d\n",n*m);else
    if(n==2||m==2)
    {
        if(m==2)swap(n,m);
        int z=0;
        if(m%4==1)z=2;
        if(m%4==2)z=4;
        if(m%4==3)z=4;
        printf("%d\n",m/4*4+z);
    }else
    if(n>=3||m>=3)printf("%d\n",(n*m+1)/2);
    return 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i+j)&1)a[i][j]=t1++;
            else a[i][j]=t0++;
    S=max(S,t0);
    t0=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(i%3==0)t0++;
    S=max(S,t0);
    t0=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(j%3==0)t0++;
    S=max(S,t0);
    printf("%d\n",S);
    return 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(~(i&j)&1)
        {
            int z=a[i][j];
            for(int d=0;d<8;d++)
            {
                int x=i+dx[d],y=j+dy[d];
                if(x>=0&&x<n&&y>=0&&y<m)b[z][l[z]++]=a[x][y];
            }
        }
    memset(c,-1,sizeof c);
    for(int i=0;i<t0;i++)
    {
        for(int j=0;j<L;j++)v[B[j]]=0;L=0;
        S+=ff(i);
    }
    printf("%d\n",n*m-S);
    return 0;
}