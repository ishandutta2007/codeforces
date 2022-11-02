#include<cstdio>
#include<cstring>

using namespace std;

int n,m,ans,b[26];
char a[110][110];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m-1;j++)
        {
            memset(b,0,sizeof b);
            b[a[i][j]-'a']=1;
            b[a[i][j+1]-'a']=1;
            b[a[i+1][j]-'a']=1;
            b[a[i+1][j+1]-'a']=1;
            if(b['f'-'a']&&b[0]&&b['c'-'a']&&b['e'-'a'])ans++;
        }
    printf("%d",ans);
}