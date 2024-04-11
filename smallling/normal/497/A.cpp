#include<cstdio> 

using namespace std;

int n,m,ans,bo;
int now[110],flag[110];
char s[110][110];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=m;i++)
    {
        bo=1;
        for(int j=1;j<n;j++)
        {
            if(!flag[j]&&s[j+1][i]<s[j][i])
            {
                bo=0;
                break;
            }
            if(s[j+1][i]>s[j][i])now[j]=1;
            else now[j]=0;
        }
        if(!bo)ans++;
        else for(int j=1;j<n;j++)if(!flag[j])flag[j]=now[j];
    }
    printf("%d",ans);
}