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
int n,q,sum[MAXN];
string str;
struct node
{
    int maxi;//maximum
    int mini;//minimum
    int pre;//maximum -2b+c
    int suf;//maximum a-2b
    int lazy;
    int ans;//maximum a-2b+c
    void init(int x)
    {
        maxi=mini=x;
        pre=suf=-x; lazy=0;
        ans=0;
    }
    void merge(node &l,node &r)
    {
        maxi=max(l.maxi,r.maxi);
        mini=min(l.mini,r.mini);
        pre=max(max(l.pre,r.pre),r.maxi-2*l.mini);
        suf=max(max(l.suf,r.suf),l.maxi-2*r.mini);
        ans=max(max(l.ans,r.ans),max(l.suf+r.maxi,l.maxi+r.pre));
    }
    void add(int x)
    {
        lazy+=x;
        maxi+=x;
        mini+=x;
        pre-=x; suf-=x;
    }
};
struct segtree
{
    node seg[4*MAXN];
    void pushup(int k)
    {
        seg[k].merge(seg[k*2],seg[k*2+1]);
    }
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++) seg[i].add(seg[k].lazy);
        seg[k].lazy=0;
    }
    void build(int k,int l,int r)
    {
        seg[k].lazy=0;
        if(l==r)
        {
            seg[k].init(sum[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            seg[k].add(v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query()
    {
        pushdown(1);
        return seg[1].ans;
    }
}sg;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    n=(int)str.size();
    for(int i=1;i<=n;i++) sum[i+1]=sum[i]+(str[i-1]=='('?1:-1);
    sg.build(1,1,n+1);
    printf("%d\n",sg.query());
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        if(str[l-1]==str[r-1]);
        else if(str[l-1]=='(')
        {
            sg.update(1,1,n+1,l+1,r,-2);
        }
        else sg.update(1,1,n+1,l+1,r,2);
        swap(str[l-1],str[r-1]);
        printf("%d\n",sg.query());
    }
    return 0;
}