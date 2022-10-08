#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define N 200010
set<PII> f[N];int x[N],y[N],z[N],p[N],n;PII c[N],q[N];char s[10];
void ask(int x,int y,int z)
{
    PII X=make_pair(x,y),S=make_pair(2e9,2e9);
    set<PII>::iterator I;
    for(;z>0;z=(z&(z+1))-1)if(f[z].size()>0)
    {
        I=f[z].lower_bound(X);
        if(I!=f[z].end()&&*I<S)S=*I;
    }
    if(S.first==2e9)puts("-1");else printf("%d %d\n",S.first,S.second);
}
void add(int x,int y,int z){PII X=make_pair(x,y);for(;z<N;z|=z+1)f[z].insert(X);}
void del(int x,int y,int z){PII X=make_pair(x,y);for(;z<N;z|=z+1)f[z].erase(X);}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",s,x+i,y+i),
        p[i]=s[0]=='a'?1:s[0]=='r'?2:3;
        if(p[i]==3)x[i]++,y[i]++;
        q[i]=make_pair(-y[i],i);
    }
    sort(q,q+n);
    for(int i=0,r=0;i<n;z[q[i].second]=r,i++)
        if(i==0||q[i].first!=q[i-1].first)r++;
    for(int i=0;i<n;i++)
        if(p[i]==3)ask(x[i],y[i],z[i]);else
        if(p[i]==2)del(x[i],y[i],z[i]);else
        if(p[i]==1)add(x[i],y[i],z[i]);
    return 0;
}