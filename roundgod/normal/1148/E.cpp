#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int n,k,a[MAXN],dif[MAXN];
P s[MAXN],t[MAXN];
ll sum[MAXN];
set<P> s1,s2;
struct node
{
    int x,y,d;
};
vector<node> ans;
int main()
{
    scanf("%d",&n);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&s[i].F); sum1+=s[i].F;
        s[i].S=i;
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&t[i].F); sum2+=t[i].F;
        t[i].S=i;
    }
    if(sum1!=sum2)
    {
        puts("NO");
        return 0;
    }
    sort(s+1,s+n+1); sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
    {
        dif[i]=t[i].F-s[i].F;
        sum[i]=sum[i-1]+dif[i];
        if(sum[i]<0)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    int l=1,r=1;
    while(l<=n&&r<=n)
    {
        while(s[l].F>=t[l].F&&l<=n) l++;
        while(s[r].F<=t[r].F&&r<=n) r++;
        if(l>r||l>n||r>n) break;
        int dif=min(t[l].F-s[l].F,s[r].F-t[r].F);
        ans.push_back((node){s[l].S,s[r].S,dif});
        s[l].F+=dif; s[r].F-=dif;
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d %d\n",p.x,p.y,p.d);
    return 0;
}