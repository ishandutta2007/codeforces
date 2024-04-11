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
int n,x;
vector<int> ans;
vector<int> v;
int main()
{
    scanf("%d%d",&n,&x);
    if(x>=(1<<n))
    {
        int last=0;
        for(int i=1;i<(1<<n);i++)
        {
            ans.push_back(last^i);
            last=i;
        }
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
    }
    else
    {
        for(int i=1;i<(1<<n);i++)
        {
            if((i^x)>i) v.push_back(i);
        }
        int last=0;
        for(int i=0;i<(int)v.size();i++)
        {
            ans.push_back(last^v[i]);
            last=v[i];
        }
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
    }
    return 0;
}