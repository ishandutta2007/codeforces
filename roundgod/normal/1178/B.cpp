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
ll n,k,a[MAXN];
string str;
int main()
{
    cin>>str;
    n=(int)str.size();
    bool last=false;
    ll lastw=0,lastwo=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(str[i]=='v')
        {
            if(last)
            {
                ans+=lastwo;
                lastw++;
            }
            last=true;
        }
        else
        {
            lastwo+=lastw;
            last=false;
        }
    }
    printf("%lld\n",ans);
    return 0;
}