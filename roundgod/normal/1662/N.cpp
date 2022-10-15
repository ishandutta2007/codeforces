#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 1505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN][MAXN],rankr[MAXN][MAXN],rankc[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        vector<P> v;
        for(int j=1;j<=n;j++) v.push_back(P(a[i][j],j));
        sort(v.begin(),v.end());
        for(int j=1;j<=n;j++) rankr[i][v[j-1].S]=j;
    }
    for(int i=1;i<=n;i++)
    {
        vector<P> v;
        for(int j=1;j<=n;j++) v.push_back(P(a[j][i],j));
        sort(v.begin(),v.end());
        for(int j=1;j<=n;j++) rankc[v[j-1].S][i]=j;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans+=(rankr[i][j]-1)*(rankc[i][j]-1);
    ll all=2LL*n*(n-1)/2*n*(n-1)/2;
    printf("%lld\n",all-ans);
    return 0;
}