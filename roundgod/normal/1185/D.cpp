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
int n,k;
P a[MAXN];
bool check(int id)
{
    int last=-1,dif=-1;
    for(int i=1;i<=n;i++)
    {
        if(i==id) continue;
        if(last==-1) {last=i; continue;}
        if(dif==-1) dif=a[i].F-a[last].F;
        else if(a[i].F-a[last].F!=dif) return false;
        last=i;
    }
    return true;
}
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a+1,a+n+1);
    if(n<=100)
    {
        for(int i=1;i<=n;i++)
        {
            if(check(i))
            {
                printf("%d\n",a[i].S);
                return 0;
            }
        }
        puts("-1");
    }
    else
    {
        for(int i=2;i<=n;i++) mp[a[i].F-a[i-1].F]++;
        if(mp.size()==1)
        {
            printf("%d\n",a[1].S);
            return 0;
        }
        bool f=false;
        int id=-1;
        for(auto x:mp)
            if(x.S>=n-3) 
            {
                f=true;
                id=x.F;
            }
        if(!f) puts("-1");
        else
        {
            for(int i=1;i<=n;i++)
            {
                if((a[i].F-a[i-1].F!=id||a[i+1].F-a[i].F!=id)&&check(i))
                {
                    printf("%d\n",a[i].S);
                    return 0;
                }
            }
            assert(0);
        }
    }
    return 0;
}