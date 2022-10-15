#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
struct dish
{
    int rem,cost,id;
}a[MAXN];
bool cmp(dish x,dish y)
{
    if(x.cost!=y.cost) return x.cost<y.cost;
    return x.id<y.id;
}
int pos[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i].rem);
    for(int i=0;i<n;i++) scanf("%d",&a[i].cost);
    for(int i=0;i<n;i++) a[i].id=i;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) pos[a[i].id]=i;
    int tot=0;
    for(int i=0;i<m;i++)
    {
        int t,d; 
        scanf("%d%d",&t,&d); t--;
        if(tot>=n) {puts("0"); continue;}
        ll ans=0;
        int need=min(d,a[pos[t]].rem);
        ans+=1LL*need*a[pos[t]].cost; a[pos[t]].rem-=need; d-=need;
        if(d>0)
        {
            while(tot<n&&d>0)
            {
                int need=min(d,a[tot].rem);
                ans+=1LL*need*a[tot].cost;
                a[tot].rem-=need;d-=need;
                if(a[tot].rem==0) tot++;
            }
            if(d>0) {puts("0"); continue;}
        }
        printf("%lld\n",ans);
    }
    return 0;
}