#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 666
map<int,set<int> >p;
map<int,int>q;
int n,m,x[N],y[N],a[N],b[N];
inline int dis(int a,int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}
void ff(int s)
{
    q.clear();
    for(int i=s;i<=n;i+=2)q[a[i]]++;
    for(map<int,int>::iterator i=q.begin();i!=q.end();i++)
        if(p[i->first].size()<i->second)return;
    puts("YES");
    memset(b,-1,sizeof b);
    for(int i=s;i<=n;i+=2)
        b[i]=*(p[a[i]].begin()),
        p[a[i]].erase(b[i]);
    for(int i=1;i<=n;i++)
        printf("%d%c",b[i],i==n?'\n':' ');
    exit(0);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        p[x].insert(i);
    }
    x[0]=x[n],y[0]=y[n],x[n+1]=x[1],y[n+1]=y[1];
    for(int i=1;i<=n;i++)a[i]=dis(i,i-1)+dis(i,i+1);
    ff(1);ff(2);puts("NO");
    return 0;
}