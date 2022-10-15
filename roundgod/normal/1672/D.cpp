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
int t,n,k,a[MAXN],b[MAXN];
bool used[MAXN];
int need[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) need[i]=0;
        vector<P> v;
        int cnt=1;
        for(int i=2;i<=n;i++)
        {
            if(b[i]==b[i-1]) cnt++;
            else {v.push_back(P(b[i-1],cnt)); cnt=1;}
        }
        v.push_back(P(b[n],cnt));
        bool f=true;
        int last=n;
        while(v.size())
        {
            P p=v.back(); v.pop_back();
            while(a[last]!=p.F&&need[a[last]]) 
            {
                need[a[last]]--;
                last--;
            }
            if(a[last]!=p.F) {f=false; break;}
            need[p.F]+=p.S-1;
            last--;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}