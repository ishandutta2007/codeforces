#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


int start[1024];
int end[1024];
int nex[1024];
int prev[1024];
int tp;
int ind;
int g=1000000;
int lamp;
    int n,p;
    int used[100007];
    int a[100007];

struct tuhla
    {
    int st;
    int en;
    int diam;
    };
struct tuhla ans[100007];
void dfs(int vertex);

int main()
    {

    int i;
    int x,y;
    int d;

    scanf("%d%d",&n,&p);
    for(i=0;i<p;i++)
        {
        scanf("%d%d%d",&x,&y,&d);
        start[x]=d;
        end[y]=d;
        nex[x]=y;
        prev[y]=x;
        }
    if(p==0){printf("0\n");return 0;}
    for(i=1;i<=n;i++)
        {
        if(end[i]==0)
            {
            ind=0;
            lamp=0;
            ans[tp].st=i;
            dfs(i);
            if(ind==0)tp++;
            }
        }
    printf("%d\n",tp);

    for(i=0;i<tp;i++)
        {
        printf("%d %d %d\n",ans[i].st,ans[i].en,ans[i].diam);
        }
    return 0;
    }


void dfs(int vertex)
    {
    if(lamp==1)return ;
    if(start[vertex]==0 && end[vertex]!=0)
        {
        ans[tp].en=vertex;
        if(g!=1000000)ans[tp].diam=g;
        else ans[tp].diam=0;
        g=1000000;
        lamp=1;
        return ;
        }
    if(start[vertex]==0 && end[vertex]==0)
        {
        ind=1;
        lamp=1;
        }
    //cout<<start[vertex]<<"\n";
    if(start[vertex]<g)g=start[vertex];
   // cout<<g<<"\n";
    dfs(nex[vertex]);
    if(lamp==1)return ;
    }