#include<stdio.h>
using namespace std;
int n,r;int ans;int len;
int str[1100000];
int biua,biub;
int dfs(int a,int b)
{
    while(1)
    {
            if(!a||!b)return a^b;
            if(len<0)return -1;
            if(b>a)
            {
                   b-=a;
                   str[len--]='B';
                   }
            else a-=b,str[len--]='T';
            }
}
void work(int a,int b)
{
     len=n;
     if(dfs(a,b)==1&&len==0)
     {
                            if(str[1]!='T')return;
                            int reu=0;
                            for(int i=2;i<=n;i++)
                            if(str[i]==str[i-1])reu++;
                            if(reu<ans)ans=reu,biua=a,biub=b;
                            }
}
int main()
{
    scanf("%d%d",&n,&r);ans=n+1;
    for(int i=1;i<=r;i++)work(i,r),work(r,i);
    if(ans==n+1)printf("IMPOSSIBLE");
    else
    {
        len=n;
        dfs(biua,biub);
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)putchar(str[i]);
        }
    return 0;
}