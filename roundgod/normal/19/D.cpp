#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int type[MAXN],x[MAXN],y[MAXN];
multiset<int> ms[MAXN];
vector<int> disx,disy;
struct segtree
{
    int maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        maxi[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int pos,int val,int tag)
    {
        if(l==r) 
        {
            if(tag) ms[l].insert(val); else ms[l].erase(ms[l].find(val));
            if(ms[l].size()) maxi[k]=*(--ms[l].end()); else maxi[k]=0;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,val,tag); else update(k*2+1,mid+1,r,pos,val,tag);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y,int val)
    {
        if(x>r||l>y) return P(INF,INF);
        if(maxi[k]<=val) return P(INF,INF);
        if(l==r)
        {
            assert(maxi[k]>val);
            int res=*ms[l].lower_bound(val+1);
            return P(l,res);
        }
        int mid=(l+r)/2;
        P p=query(k*2,l,mid,x,y,val); if(p.F!=INF) return p;
        return query(k*2+1,mid+1,r,x,y,val);
    }
}seg;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str=="remove") type[i]=1; else if(str=="find") type[i]=2;
        scanf("%d%d",&x[i],&y[i]);
        disx.push_back(x[i]); disy.push_back(y[i]);
    }
    sort(disx.begin(),disx.end()); disx.erase(unique(disx.begin(),disx.end()),disx.end());
    sort(disy.begin(),disy.end()); disy.erase(unique(disy.begin(),disy.end()),disy.end());
    int sz=(int)disx.size();
    seg.build(1,1,sz);
    for(int i=0;i<n;i++)
    {
        x[i]=lower_bound(disx.begin(),disx.end(),x[i])-disx.begin()+1;
        y[i]=lower_bound(disy.begin(),disy.end(),y[i])-disy.begin()+1;
        if(type[i]==0) seg.update(1,1,sz,x[i],y[i],1);
        else if(type[i]==1) seg.update(1,1,sz,x[i],y[i],0);
        else
        {
            P p=seg.query(1,1,sz,x[i]+1,sz,y[i]);
            if(p.F==INF) puts("-1"); else printf("%d %d\n",disx[p.F-1],disy[p.S-1]);
        }
    }
    return 0;
}