#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000010
#define L 20
int f[N][L],n,r,c;char s[N*6];int st[N],le[N],ws[N];
inline bool can(int l,int r)
{
    return ws[r]-ws[l]+r-l-1<=c;
}
inline int ff(int x,int y)
{
    for(int i=L-1;i>=0;i--)
        if((y>>i)&1)x=f[x][i];
    return x;
}
int main()
{
    scanf("%d%d%d",&n,&r,&c);
    for(int i=0,la=0;i<n;i++)
    {
        scanf("%s",s+la);
        st[i]=la,le[i]=strlen(s+la);
        la+=le[i]+1;
    }
    ws[0]=0;
    for(int i=0;i<n;i++)
        ws[i+1]=ws[i]+le[i];
    for(int i=0,j=0;i<n;i++)
    {
        while(j<n&&can(i,j+1))j++;
        f[i][0]=j;
    }
    for(int i=0;i<L;i++)f[n][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<L;j++)f[i][j]=f[f[i][j-1]][j-1];
    }
    int p=-1,w=-1;
    for(int i=0;i<n;i++)
    {
        int j=ff(i,r);
        if(j-i>w)w=j-i,p=i;
    }
    for(int i=0;i<r;i++)
    {
        int q=p;
        while(q<n&&can(p,q+1))
        {
            if(q>p)putchar(' ');
            printf("%s",s+st[q]),q++;
        }
        if(p==q)break;
        p=q;
        puts("");
    }
    return 0;
}