#include<stdio.h>
using namespace std;
int n,m;
void max(int &x,int y){if(y>x)x=y;}
int main()
{
    scanf("%d%d",&n,&m);
    if(n==1||m==1){printf("%d\n",n+m-1);return 0;}
    if(n==2&&m==2){printf("4\n");return 0;}
    if(n==2)
    {
             int c=0;
             for(int j=0;j<m;j++)if(j%4==0||j%4==1)c++;
             printf("%d\n",2*c);
             return 0;
             }
    if(m==2)
    {
            int c=0;
            for(int j=0;j<n;j++)if(j%4<=1)c++;
            printf("%d\n",2*c);
            return 0;
            }
    int ans=0;
    if(n&1)max(ans,m*(n/2)+(m/2)+(m&1));
    else max(ans,(n/2)*m);
    int tmp=n;n=m;m=tmp;
    if(n&1)max(ans,m*(n/2)+(m/2)+(m&1));
    else max(ans,(n/2)*m);
    printf("%d\n",ans);
    return 0;
}