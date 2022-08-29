#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
char str[105][3];
char tmp[105][3];
long ans=210000;
char biao[6]={'s','W','Y','B','G','R'};
long ask[255];
long n,tot;
bool use1[6]={false};
bool use2[6]={false};
bool sb[105]={false};
void init()
{
     ask['W']=1;
     ask['Y']=2;
     ask['B']=3;
     ask['G']=4;
     ask['R']=5;
}
long ld[6];
long ld2[6];
void check()
{
     memset(ld,0,sizeof ld);
     memset(ld2,0,sizeof ld2);
     memset(sb,false,sizeof sb);
     long reu=0;
     for(long i=1;i<=5;i++){reu+=use1[i];reu+=use2[i];}
     if(reu>ans)return;
     for(long i=1;i<=tot;i++)
     {
              sb[i]=(use1[ask[tmp[i][1]]]&&use2[tmp[i][2]-48]);
              if(!sb[i])
              {
                        ld[ask[tmp[i][1]]]++;
                        ld2[tmp[i][2]-48]++;
                        }
                        }
     for(long i=1;i<=tot;i++)
     for(long j=1;j<=tot;j++)
     if(!sb[j])
     if((ld[ask[tmp[j][1]]]==1&&use1[ask[tmp[j][1]]])||(ld2[tmp[j][2]-48]==1&&use2[tmp[j][2]-48]))
     {
                                                    sb[j]=true;
                                                    ld[ask[tmp[j][1]]]--;
                                                    ld2[tmp[j][2]-48]--;
                                                    }
     long flag=0;
     for(long i=1;i<=tot;i++)if(!sb[i])flag++;
     if(flag>1)return;
     ans=reu;
}
void dfs2(long step)
{
     if(step>5)check();
     else
     {
         use2[step]=true;
         dfs2(step+1);
         use2[step]=false;
         dfs2(step+1);
         }
}
void dfs1(long step)
{
     if(step>5)dfs2(1);
     else
     {
         use1[step]=true;
         dfs1(step+1);
         use1[step]=false;
         dfs1(step+1);
         }
}
map<long,long>have;
int main()
{
    scanf("%ld",&n);init();
    for(long i=1;i<=n;i++)
    {
             scanf("%s",str[i]+1);
             long x=str[i][1]*100+str[i][2];
             if(have[x]==0)
             {
                           have[x]=1;
                           tot++;
                           tmp[tot][1]=str[i][1];
                           tmp[tot][2]=str[i][2];
                           }
                           }
    dfs1(1);
    printf("%ld\n",ans);
    return 0;
}