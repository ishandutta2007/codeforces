#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int shift=500000;
struct segtree
{
    int mini[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v)
    {
        mini[k]+=v; lazy[k]+=v;
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            mini[k]=l-shift;
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
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int n,a[MAXN];
multiset<int> smaller;
multiset<int> larger;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,0,1000000);
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<cur)
        {
            if(!smaller.size()) 
            {
                cur--;
                smaller.insert(a[i]);
            }
            else
            {
                int val=(*--smaller.end()); smaller.erase(smaller.find(val)); 
                smaller.insert(a[i]); larger.insert(val);
                if(larger.size()&&(*larger.begin()<cur))
                {
                    cur--; smaller.insert(*larger.begin());
                    larger.erase(larger.begin());
                }
            }
        }
        else larger.insert(a[i]);
        //printf("i=%d cur=%d\n",i,cur);
        seg.update(1,0,1000000,-500000+shift,a[i]-1+shift,1);
        printf("%d\n",seg.query(1,0,1000000,cur+shift,500000+shift));
    }
    return 0;
}