#include<stdio.h>
#define MAXN 2005
using namespace std;
int ans[MAXN][MAXN];int tot=2;
int st,ed;
void line(int a,int b)
{
     ans[a][b]=ans[b][a]=1;
}
void build(int d)
{
     st=++tot;
     for(int i=1;i<=d;i++)
     {
             int t1=++tot;
             int t2=++tot;
             int t3=++tot;
             if(i==1)
             {
                     line(st,t1);
                     line(st,t2);
                     line(st,t3);
                     }
             else
             {
                 line(t1-1,t1);
                 line(t1-2,t1);
                 line(t1-3,t1);
                 line(t1-1,t2);
                 line(t1-2,t2);
                 line(t1-3,t2);
                 line(t1-1,t3);
                 line(t1-2,t3);
                 line(t1-3,t3);
                 }
             if(i==d)
             {
                     ++tot;
                     line(t1,tot);
                     line(t2,tot);
                     line(t3,tot);
                     }
                     }
     if(!d)line(st,++tot);
     ed=tot;
     for(int i=1;i<=31-d;i++)
     {
             line(ed,++tot);
             ed=tot;
             }
}    
int main()
{
    int k;scanf("%d",&k);int d=0;
    while(k)
    {
            if(k%3)
            {
                   build(d);
                   line(2,ed);
                   if(k%3==1)
                   {
                             tot++;
                             line(1,tot);
                             line(tot,st);
                             }
                   else
                   {
                       tot++;
                       line(1,tot);
                       line(tot,st);
                       tot++;
                       line(1,tot);
                       line(tot,st);
                       }
                   }
            //printf("%d\n",ed);
            k/=3;d++;
            }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
    {
            for(int j=1;j<=tot;j++)
            if(ans[i][j])putchar('Y');
            else putchar('N');
            putchar('\n');
            }
    return 0;
}