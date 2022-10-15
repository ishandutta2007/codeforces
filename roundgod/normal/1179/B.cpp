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
int n,m;
vector<P> ans;
void solve(int x)
{
    ans.push_back(make_pair((x-1)/m+1,(x-1)%m+1));
}
int main()
{
    scanf("%d%d",&n,&m);
    int l=1,r=n*m;
    while(l<=r)
    {
        solve(l);
        l++;
        if(l<=r)
        {
            solve(r);
            r--;
        }
    }
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}