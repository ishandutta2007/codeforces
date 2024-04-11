#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int N_MAX=100000+10;
int n,m;int ret[N_MAX]={};
int next[N_MAX],b[N_MAX],v[N_MAX];
int F[N_MAX],LN[N_MAX];
bool Mark[N_MAX]={};
void Find(int t)
{
    if(F[t]==t)return;
    Find(F[t]);LN[t]+=LN[F[t]];
    F[t]=F[F[t]];
}
void Union(int t,int f)
{
    Find(f);Find(t);
    if(F[f]==F[t])
    {
        return;
    }
    F[t]=f;LN[t]=1;
}
void visit(int ti,int a,int b)
{
    for(;;)
    {
        Find(a);int t=F[a];
        if(Mark[t])return;
        b-=LN[a];
        if(b<0)return;
        Mark[t]=true;
        ret[ti]++;
        Union(t,next[t]);
        a=t;
    }
}
int main()
{
    //freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    rep(i,n)scanf("%d",next+i),next[i]--,F[i]=i,LN[i]=0;
    rep(i,m)scanf("%d",v+i);
    rep(i,m)scanf("%d",b+i);
    rep(i,m)
    {
        int a=(v[i]+ret[i]-1)%n;
        visit(i+1,a,b[i]-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ret[i]);
}