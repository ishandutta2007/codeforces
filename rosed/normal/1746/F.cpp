#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit ((i)&(-i))
mt19937 rnd(time(0));
const int mod=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> c;
    typedef array<int,10> node;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        c.emplace_back(a[i]);
    }
    vector<int> ret(m+1,1);
    typedef array<int,4> pr;
    vector<pr> q(m+1);
    for(int i=1;i<=m;++i)
    {
        cin>>q[i][0]>>q[i][1]>>q[i][2];
        if(q[i][0]==1)
        {
            c.emplace_back(q[i][2]);
        }
        else
        {
            cin>>q[i][3];
        }
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    int num=c.size();
    vector<node> val(num+1);
    for(int i=1;i<=n;++i)
    {
        a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin();
    }
    for(int i=1;i<=m;++i)
    {
        if(q[i][0]==1)
        {
            q[i][2]=lower_bound(c.begin(),c.end(),q[i][2])-c.begin();
        }
    }

    int tt=3;
    while(tt--)
    {
        for(int i=0;i<num;++i)
        {
            for(int k=0;k<10;++k)
            {
                val[i][k]=rnd()*rnd()%mod+1;
            }
        }
        vector<node> ans(4*n+5);
        function<void(int,int,int)> build=[&](int l,int r,int p) -> void
        {
            if(l==r)
            {
                for(int k=0;k<10;++k) ans[p][k]=val[a[l]][k];
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            for(int k=0;k<10;++k) ans[p][k]=ans[ls(p)][k]+ans[rs(p)][k];
        };
        build(1,n,1);
        function<void(int,int,int,int,int)> update=[&](int pos,int l,int r,int p,int x) -> void
        {
            if(l==r)
            {
                for(int k=0;k<10;++k) ans[p][k]=val[x][k];
                return;
            }
            if(pos<=mid) update(pos,l,mid,ls(p),x);
            else update(pos,mid+1,r,rs(p),x);
            for(int k=0;k<10;++k) ans[p][k]=ans[ls(p)][k]+ans[rs(p)][k];
        };
        function<node(int,int,int,int,int)> query=[&](int tl,int tr,int l,int r,int p) -> node
        {
            if(tl<=l&&r<=tr) return ans[p];
            if(tr<=mid) return query(tl,tr,l,mid,ls(p));
            if(tl>mid) return query(tl,tr,mid+1,r,rs(p));
            node t1=query(tl,tr,l,mid,ls(p)),t2=query(tl,tr,mid+1,r,rs(p));
            for(int k=0;k<10;++k) t1[k]+=t2[k];
            return t1;
        };
        for(int i=1;i<=m;++i)
        {
            if(q[i][0]==1)
            {
                update(q[i][1],1,n,1,q[i][2]);
            }
            else
            {
                node tmp=query(q[i][1],q[i][2],1,n,1);
                bool flag=1;
                for(int k=0;k<10;++k)
                {
                    if(tmp[k]%q[i][3]!=0) flag=0;
                }
                if(!flag) ret[i]=0;
            }
        }
    }
    for(int i=1;i<=m;++i) if(q[i][0]==2)
        if(ret[i]) cout<<"YES\n";
        else cout<<"NO\n";
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}