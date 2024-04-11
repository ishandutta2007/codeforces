#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
bool marked[MAXN];
vector<P> v;
vector<int> ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(marked,false,sizeof(marked));
    for(int i=1;i<=n;i++) v.push_back(P(a[i],i));
    sort(v.begin(),v.end(),greater<>());
    ll sum=0;
    for(int i=0;i<m*k;i++) 
    {
        sum+=v[i].F;
        marked[v[i].S]=true;
    }
    printf("%lld\n",sum);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(marked[i]) cnt++;
        if(cnt==m) 
        {
            ans.push_back(i);
            cnt=0;
        }
    }
    for(int i=0;i<k-1;i++) printf("%d ",ans[i]);
    return 0;
}