#include<bits/stdc++.h>
#define MAXN 300050
#define INF 1000000000
using namespace std;
typedef long long ll;
struct fl
{
    int cost;
    int time;
}a[MAXN];
int n,k;
bool cmp(fl x,fl y)
{
    if(x.cost!=y.cost) return x.cost>y.cost;
    return x.time>y.time;
}
set<int> num;
int save[MAXN];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].cost);
        a[i].time=i+1;
    }
    sort(a,a+n,cmp);
    num.clear();
    for(int i=1;i<=n;i++)
        num.insert(i+k);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        set<int>::iterator it=num.lower_bound(a[i].time);
        ans+=(ll)(*it-a[i].time)*a[i].cost;
        save[a[i].time-1]=*it;
        num.erase(*it);
    }
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++)
        printf("%d\n",save[i]);
    return 0;
}