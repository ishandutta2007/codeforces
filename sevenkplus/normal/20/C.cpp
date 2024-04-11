#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 101000
#define MAX 1000000000000000LL
typedef long long ll;
bool c[N];
ll a[N],e[N];
int n,m,w[N],q[N],p[N],l[N];
vector<pair<int,ll> >b[N];
void D(int x)
{
    int d=x,c;
    ll X=q[d];
    for(;d*2<=n;)
    {
        c=d*2;
        if(c<n&&a[q[c+1]]<a[q[c]])
            c++;
        if(a[q[c]]<a[X])
            q[d]=q[c],w[q[d]]=d,d=c;
        else
            break;
    }
    w[X]=d,q[d]=X;
}
void U(int x)
{
    int d=x,f;
    ll X=q[d];
    for(;d>1;)
    {
        f=d/2;
        if(a[q[f]]>a[X])
            q[d]=q[f],w[q[d]]=d,d=f;
        else
            break;
    }
    w[X]=d,q[d]=X;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,x,y;
    ll d;
    for(i=1;i<=n;a[i]=e[i]=MAX,b[i].clear(),w[i]=i,q[i]=i,i++);
    for(a[1]=0,i=0;i<m;scanf("%d%d%I64d",&x,&y,&d),b[x].push_back(make_pair(y,d)),b[y].push_back(make_pair(x,d)),i++);
    for(;a[q[1]]!=MAX;)
    {
        x=q[1],d=e[x]=a[x],a[x]=MAX,c[x]=1,D(1);
        for(vector<pair<int,ll> >::iterator I=b[x].begin();I!=b[x].end();I++)
            if(!c[I->first]&&a[I->first]>d+I->second)
                a[I->first]=d+I->second,p[I->first]=x,U(w[I->first]);
    }
    if(e[n]==MAX)
        puts("-1");
    else
    {
        int t=0;
        for(i=n;i;l[++t]=i,i=p[i]);
        for(i=t;i>1;printf("%d ",l[i]),i--);
        printf("%d\n",l[1]);
    }
    return 0;
}