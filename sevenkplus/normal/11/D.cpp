#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll f[20][600000],s;
int n,m,x,y,i,j,k,l,a[20],p[20];
int main()
{
    for(i=0;i<20;p[i]=1<<i,i++);
    for(scanf("%d%d",&n,&m);m--;scanf("%d%d",&x,&y),x--,y--,a[x]|=p[y],a[y]|=p[x],f[max(x,y)][p[x]+p[y]]=1);
    for(i=1;i<1<<n;i++)
        for(j=0,k=20;j<n;j++)
            if(i&p[j]&&!f[j][i])
            {
                if(k==20){k=j;continue;}
                for(y=k+1;y<n;y++)
                    if(i&p[y]&&a[y]&p[j])
                        f[j][i]+=f[y][i^p[j]];
                if(a[k]&p[j])
                    s+=f[j][i];
            }
    printf("%I64d\n",s/2);
    return 0;
}