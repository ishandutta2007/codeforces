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
int t,n,k,a[MAXN];
int cnt[MAXN];
vector<int> pos[MAXN];
bool cmp(int x,int y)
{
    return cnt[x]>cnt[y];
}
void rot(vector<int> &v)
{
    int tmp=a[v[0]];
    for(int i=0;i<(int)v.size()-1;i++) a[v[i]]=a[v[i+1]];
    a[v.back()]=tmp;
}
vector<int> id;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        id.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) pos[i].clear();
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]++;
            pos[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) if(cnt[i]) id.push_back(i);
        sort(id.begin(),id.end(),cmp);
        while(id.size()>1)
        {
            vector<int> tmp; tmp.clear();
            for(auto x:id) 
            {
                tmp.push_back(pos[x].back());
                pos[x].pop_back();
            }
            rot(tmp);
            while(id.size()>1&&pos[id.back()].size()==0) id.pop_back();
        }
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}