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
int n,k,m,t;
int main()
{
    scanf("%d%d%d%d",&n,&k,&m,&t);
    for(int i=0;i<t;i++)
    {
        int type,x;
        scanf("%d%d",&type,&x);
        if(type==1)
        {
            if(x<=k) k++;
            n++;
        }
        else
        {
            if(x>=k)
            {
                n=x;
            }
            else
            {
                n=n-x;
                k=k-x;
            }
        }
        printf("%d %d\n",n,k);
    }
    return 0;
}