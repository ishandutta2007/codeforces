#include<cstdio>
#include<vector>
using namespace std;
#define N 111111
int a[N],b[N],n;
bool c[N],d[N],v[N];
vector<int>p,q;
#define pb push_back
void ff(int x){v[x]=1;if(!v[a[x]])ff(a[x]);b[x]=b[a[x]];if(!b[x])b[x]=x;}
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",a+i),c[a[i]]=1;
    for(int i=1;i<=n;i++)if(!v[i])ff(i);
    for(int i=1;i<=n;i++)if(!c[i])p.pb(i),q.pb(b[i]),d[b[i]]=1;
    for(int i=1;i<=n;i++)if(b[i]==i&&!d[i])p.pb(i),q.pb(i);
    n=p.size();if(n==1&&p[0]==q[0])n=0;printf("%d\n",n);
    for(int i=0;i<n;i++)printf("%d %d\n",q[i],p[(i+1)%n]);
    return 0;
}