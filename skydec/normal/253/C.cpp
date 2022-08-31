#include<stdio.h>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
#define MAXN 110000
using namespace std;
int n;
int data[MAXN];
int dis[102][MAXN];
pii q[MAXN*102];
int tot=0;
pii st,ed;
int min(int a,int b){if(a<b)return a;return b;}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&data[i]);data[i]++;}
    scanf("%d%d",&st.fi,&st.se);
    scanf("%d%d",&ed.fi,&ed.se);
    tot=0;
    dis[st.fi][st.se]=1;
    q[tot=1]=st;
    for(int i=1;i<=tot;i++)
    {
            pii now=q[i];
            pii yes;
            if(now.fi!=1)
            {
                         yes=pii(now.fi-1,min(now.se,data[now.fi-1]));
                         if(!dis[yes.fi][yes.se])
                         {
                          dis[yes.fi][yes.se]=dis[now.fi][now.se]+1;
                          q[++tot]=yes;
                          }
                          }
            if(now.fi!=n)
            {
                         yes=pii(now.fi+1,min(now.se,data[now.fi+1]));
                         if(!dis[yes.fi][yes.se])
                         {
                          dis[yes.fi][yes.se]=dis[now.fi][now.se]+1;
                          q[++tot]=yes;
                          }
                          }
            if(now.se!=1)
            {
                         yes=pii(now.fi,now.se-1);
                         if(!dis[yes.fi][yes.se])
                         {
                          dis[yes.fi][yes.se]=dis[now.fi][now.se]+1;
                          q[++tot]=yes;
                          }
                          }
            if(now.se!=data[now.fi])
            {
                         yes=pii(now.fi,now.se+1);
                         if(!dis[yes.fi][yes.se])
                         {
                          dis[yes.fi][yes.se]=dis[now.fi][now.se]+1;
                          q[++tot]=yes;
                          }
                          }
                          }
    printf("%d\n",dis[ed.fi][ed.se]-1);
    return 0;
}