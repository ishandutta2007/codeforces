#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int i,j,k,l,m,n,o,p;
char a[101][101],ch;
bool b[101][101],bo;
int main()
{
    scanf("%d\n",&n);
    memset(b,false,sizeof(b));
    for(i=1;i<=n;i++)
    {
                     for(j=1;j<=n;j++)
                     {
                                      scanf("%c",&a[i][j]);
                                      if(a[i][j]=='#')b[i][j]=true;
                     }
                     scanf("%c",&ch);
    }
    bo=true;
    for(i=1;i<=n;i++)
    {
                     for(j=1;j<=n;j++)
                     if(b[i][j]==true)
                     {
                                      if(b[i+1][j]==true)b[i+1][j]=false;else {bo=false;break;}
                                      if(b[i+1][j-1]==true)b[i+1][j-1]=false;else {bo=false;break;}
                                      if(b[i+1][j+1]==true)b[i+1][j+1]=false;else {bo=false;break;}
                                      if(b[i+2][j]==true)b[i+2][j]=false;else {bo=false;break;}
                     }
                     if(bo==false)break;
    }
    if(bo==true)printf("YES");
    else printf("NO");
}