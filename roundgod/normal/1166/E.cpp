#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 55
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
typedef bitset<10005> bs;
bs a[MAXN];
int m,n;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        int k;scanf("%d",&k);
        a[i].reset();
        for(int j=0;j<k;j++) 
        {
            int x;scanf("%d",&x);
            a[i].set(x-1);
        }
    }
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
        {
            if(!((a[i]&a[j]).count())) 
            {
                puts("impossible");
                return 0;
            }
        }
    puts("possible");
    return 0;
}