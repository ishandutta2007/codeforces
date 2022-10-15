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
ll l,tot;
string str;
const ll val=(1LL<<32);
ll st[MAXN];
ll cur;
int main()
{
    scanf("%lld ",&l);
    st[0]=1; tot=1;
    for(ll i=0;i<l;i++)
    {
        getline(cin,str);
        if(str[0]=='f')
        {
            ll x=atoi(str.substr(4).c_str());
            st[tot]=min(st[tot-1]*x,val); tot++;
        }
        else if(str[0]=='a')
        {
            cur+=st[tot-1];
        }
        else 
        {
            tot--;
        }
    }
    if(cur>=val) puts("OVERFLOW!!!"); else printf("%lld\n",cur);
    return 0;
}