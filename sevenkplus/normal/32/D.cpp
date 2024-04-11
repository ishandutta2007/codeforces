#include<cstdio>
#include<algorithm>
using namespace std;
char a[310][310];int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int r=1;r<n;r++)
        for(int i=r;i<n-r;i++)
            for(int j=r;j<m-r;j++)
                if(a[i][j]=='*'&&a[i][j+r]=='*'&&a[i][j-r]=='*'&&a[i+r][j]=='*'&&a[i-r][j]=='*')
                {
                    --k;
                    if(!k)
                    {
                        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+1,j+1,i-r+1,j+1,i+r+1,j+1,i+1,j-r+1,i+1,j+r+1);
                        return 0;
                    }
                }
    puts("-1");
    return 0;
}