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
int q;
ll a,b,m;
ll cont[MAXN],scont[MAXN];
int main()
{
    cont[1]=cont[2]=1;
    for(int i=3;i<=50;i++) cont[i]=cont[i-1]*2;
    for(int i=1;i<=50;i++) scont[i]=scont[i-1]+cont[i];
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&m);
        if(a==b)
        {
            printf("1 %lld\n",a);
            continue;
        }
        ll res=a+1,res2=a+m,cut=a;
        bool f=false;
        for(int i=2;i<=50;i++)
        {
            if(res>b) break;
            if(b<=res2)
            {
                printf("%d ",i);
                f=true;
                vector<ll> v; v.push_back(a);
                ll need=b-cut;
                ll sum=a;
                for(int j=1;j<=i-1;j++)
                {
                    ll get=(j==i-1?need:min(m,(need-scont[i-j-1])/cont[i-j]));
                    v.push_back(sum+get);
                    sum+=sum+get;
                    need-=get*cont[i-j];
                }
                for(auto x:v) printf("%lld ",x);
                puts("");
                break;
            }
            res=res*2;
            res2=res2*2;
            cut=cut*2;
        }
        if(!f) puts("-1");
    }
    return 0;
}