#include<cstdio>
#include<algorithm>
using namespace std;
char a[500][500],b[5][5];int n,m,p[10];
void ff(int m,int x,int y)
{
    if(m==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[x+i][y+j]=b[i][j];
        return;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(b[i][j]=='*')
                for(int k=0;k<p[m-1];k++)
                    for(int l=0;l<p[m-1];l++)
                        a[x+i*p[m-1]+k][y+j*p[m-1]+l]='*';
            else ff(m-1,x+i*p[m-1],y+j*p[m-1]);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",b[i]);
    p[0]=1;for(int i=0;i<m;i++)p[i+1]=p[i]*n;
    ff(m,0,0);
    for(int i=0;i<p[m];i++)printf("%s\n",a[i]);
    return 0;
}