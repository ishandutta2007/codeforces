#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
int n,k,a[MAXN];
int cnt[MAXN],last[MAXN],fst[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) fst[i]=INF;
    for(int i=1;i<=k;i++) 
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        fst[a[i]]=min(fst[a[i]],i);
        last[a[i]]=max(last[a[i]],i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!cnt[i]) ans++;
        if(i<n&&(!cnt[i]||!cnt[i+1])) ans+=2;
        else if(i<n&&cnt[i]&&cnt[i+1]&&(fst[i+1]>last[i]||last[i+1]<fst[i])) ans++;
    }
    printf("%d\n",ans);
    return 0;
}