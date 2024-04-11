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
int n,m,k,a[MAXN];
vector<int> v;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) v.push_back(a[i]-a[i-1]-1);
    sort(v.begin(),v.end());
    int need=n-k;
    ll ans=n;
    for(int i=0;i<need;i++) ans+=v[i];
    printf("%lld\n",ans);
    return 0;
}