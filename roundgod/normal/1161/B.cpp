#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,m,a[MAXN],b[MAXN];
unordered_set<int> x[MAXN];
unordered_set<int> us;
bool check(int d)
{
    for(auto i:us)
    {
        if((int)x[i].size()%(n/d)!=0) return false;
        for(auto j:x[i]) if(!x[i].count((j+d)%n)) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        int d=(b[i]-a[i]+n)%n;
        if(d>n/2) swap(a[i],b[i]);
        d=(b[i]-a[i]+n)%n;
        us.insert(d);
        x[d].insert(a[i]%n);
        if(d==n/2) x[d].insert(b[i]%n);
    }
    for(auto i:us)
    {
        if(x[i].size()==1)
        {
            puts("No");
            return 0;
        }
    }
    for(int i=1;i*i<=n;i++)
    {
        if(n%i) continue;
        if(check(i)) {puts("Yes"); return 0;}
        if(i!=1&&check(n/i)) {puts("Yes"); return 0;}
    }
    puts("No");
    return 0;
}