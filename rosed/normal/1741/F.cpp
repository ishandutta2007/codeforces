#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int inf=1e12;
void solve()
{
    int n;
    cin>>n;
    typedef array<int,3> node;
    vector<vector<node> > a(n+1);
    vector<int> c;
    for(int i=1;i<=n;++i)
    {
        int l,r,col;
        cin>>l>>r>>col;
        a[col].emplace_back(node{l,r,i});
        c.emplace_back(l);
        c.emplace_back(r);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    int num=c.size();
    vector<node> ans(4*num+5);
    vector<int> tag(4*num+5);
    function<void(int,int,int)> build=[&](int l,int r,int p) -> void
    {
        ans[p][0]=0;
        ans[p][1]=-inf;
        ans[p][2]=inf;
        tag[p]=0;
        if(l==r) return;
        build(l,mid,ls(p));
        build(mid+1,r,rs(p));
    };
    auto work=[&](int l,int r,int p) -> void
    {
        ans[p][0]=r-l+1;
        ans[p][1]=r;
        ans[p][2]=l;
        tag[p]=1;
    };
    auto pushdown=[&](int l,int r,int p) -> void
    {
        work(l,mid,ls(p));
        work(mid+1,r,rs(p));
        tag[p]=0;
    }; 
    function<void(int,int,int,int,int)> update=[&](int tl,int tr,int l,int r,int p) -> void
    {
        if(tl<=l&&r<=tr)
        {
            work(l,r,p);
            return;
        }
        if(tag[p]) pushdown(l,r,p);
        if(tl<=mid) update(tl,tr,l,mid,ls(p));
        if(tr>mid) update(tl,tr,mid+1,r,rs(p));
        ans[p][0]=ans[ls(p)][0]+ans[rs(p)][0];
        ans[p][1]=max(ans[ls(p)][1],ans[rs(p)][1]);
        ans[p][2]=min(ans[ls(p)][2],ans[rs(p)][2]);
    };
    function<int(int,int,int,int)> query1=[&](int pos,int l,int r,int p) -> int
    {
        if(r<=pos) return ans[p][1];
        if(tag[p]) pushdown(l,r,p);
        if(pos<=mid) return query1(pos,l,mid,ls(p));
        return max(ans[ls(p)][1],query1(pos,mid+1,r,rs(p)));
    };
    function<int(int,int,int,int)> query2=[&](int pos,int l,int r,int p) -> int
    {
        if(l>=pos) return ans[p][2];
        if(tag[p]) pushdown(l,r,p);
        if(pos>mid) return query2(pos,mid+1,r,rs(p));
        return min(ans[rs(p)][2],query2(pos,l,mid,ls(p)));
    };
    vector<int> ret(n+1,inf);
    build(1,num,1);
    for(int col=1;col<=n;++col)
    {
        for(auto &[l,r,id]:a[col])
        {
            l=lower_bound(c.begin(),c.end(),l)-c.begin()+1;
            r=lower_bound(c.begin(),c.end(),r)-c.begin()+1;
            int tmp=query1(r,1,num,1);
            if(tmp>=1) ret[id]=min(ret[id],max(0ll,c[l-1]-c[tmp-1]));
            tmp=query2(l,1,num,1);
            if(tmp<=num) ret[id]=min(ret[id],max(0ll,c[tmp-1]-c[r-1]));
        }
        for(auto [l,r,id]:a[col]) update(l,r,1,num,1);
    }
    build(1,num,1);
    for(int col=n;col>=1;--col)
    {
        for(auto &[l,r,id]:a[col])
        {
            int tmp=query1(r,1,num,1);
            if(tmp>=1) ret[id]=min(ret[id],max(0ll,c[l-1]-c[tmp-1]));
            tmp=query2(l,1,num,1);
            if(tmp<=num) ret[id]=min(ret[id],max(0ll,c[tmp-1]-c[r-1]));
        }
        for(auto [l,r,id]:a[col]) update(l,r,1,num,1);
    }
    for(int i=1;i<=n;++i) cout<<ret[i]<<" \n"[i==n];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}