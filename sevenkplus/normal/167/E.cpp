#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 610
#define M 100010
int px[M],py[M],n,m,L0,L1,L,p0[N],p1[N],p[N],dt[N],dn[N],vl[N],tp[N],P,f[N][N],q[N],v[N][N],g[N][N];
void gcd(int a,int b,int &x,int &y)
{
    if(b==0){x=1,y=0;return;}
    gcd(b,a%b,y,x),y-=a/b*x;
}
int inv(int n)
{
    int x,y;gcd(n,P,x,y);
    if(x<0)x+=P;return x;
}
int main()
{
    scanf("%d%d%d",&n,&m,&P);
    for(int i=0;i<m;i++)
        scanf("%d%d",px+i,py+i),px[i]--,py[i]--,
        dt[px[i]]++,dn[py[i]]++,v[px[i]][py[i]]++;
    for(int i=0;i<n;i++)
        if(dt[i]||dn[i])
        {
            p[L++]=i;
            if(dt[i]&&!dn[i])p0[L0++]=i;
            if(dn[i]&&!dt[i])p1[L1++]=i;
        }
    int S=1;
    for(int i=0;i<n;i++)
        if(!dt[i]&&!dn[i])
        {
            int x=0,y=0;
            for(int j=0;j<L0;j++)
                if(p0[j]<i)x++;
            for(int j=0;j<L1;j++)
                if(p1[j]<i)y++;
            if((x+y)&1){S=-S;if(S<0)S+=P;}
        }
    if(!p0&&!p1){printf("%d\n",S);return 0;}
    int le=0,ri=0;
    for(int i=0;i<L1;i++)q[ri++]=p1[i],f[p1[i]][i]=1;
    while(le<ri)
    {
        int x=q[le++];
        for(int y=0;y<n;y++)if(v[y][x])
        {
            for(int i=0;i<L1;i++)
                f[y][i]=(f[y][i]+(ll)f[x][i]*v[y][x]%P)%P;
            dt[y]-=v[y][x];
            if(!dt[y])q[ri++]=y;
        }
    }
    for(int i=0;i<L0;i++)
        for(int j=0;j<L1;j++)
            g[i][j]=f[p0[i]][j];
    for(int i=0;i<L0;i++)
    {
        if(!g[i][i])
        {
            S=-S;
            if(S<0)S+=P;
            for(int j=i+1;j<L0;j++)if(g[j][i])
            {
                for(int k=0;k<L0;k++)swap(g[i][k],g[j][k]);
                break;
            }
        }
        if(!g[i][i]){puts("0");return 0;}
        for(int j=i+1;j<L0;j++)
        {
            int w=(ll)g[j][i]*inv(g[i][i])%P;
            for(int k=0;k<L0;k++)
            {
                g[j][k]-=(ll)g[i][k]*w%P;
                if(g[j][k]<0)g[j][k]+=P;
            }
        }
    }
    for(int i=0;i<L0;i++)S=(ll)S*g[i][i]%P;
    printf("%d\n",S);
    return 0;
}