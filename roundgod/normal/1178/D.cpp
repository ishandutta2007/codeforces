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
int n;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<P> edges;
bool vis[MAXN];
int main()
{
    sieve(100000);
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        edges.push_back(P(i,i+1));
    }
    edges.push_back(P(1,n));
    memset(vis,false,sizeof(vis));
    for(int i=1;i+2<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;
        vis[i+2]=true;
        int sz=(int)edges.size();
        if(is_prime[sz]) break;
        edges.push_back(P(i,i+2));
    }
    printf("%d\n",(int)edges.size());
    for(auto p:edges) printf("%d %d\n",p.F,p.S);
    return 0;
}