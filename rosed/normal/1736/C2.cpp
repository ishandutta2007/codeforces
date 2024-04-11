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

    vector<int> a(n+1),p(n+1),val(n+1);
    vector<int> suf(n+2);
    int tot=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=min(a[i],p[i-1]+1);
        tot+=p[i];
    }
    for(int i=n;i>=1;--i)
    {
        if(i!=n) suf[i]+=suf[i+1];
        suf[i]+=p[i];
    }
    for(int i=1;i<=n;++i)
    {
        val[i]=max(0ll,a[i]-(p[i-1]+1));
        // cout<<i<<' '<<p[i]<<"!!"<<endl;
    }
    int m;
    cin>>m;
    typedef array<int,3> pr;
    vector<pr> q(m+1);
    for(int i=1;i<=m;++i)
    {
        cin>>q[i][0]>>q[i][1];
        q[i][2]=i;
    }
    vector<int> cc(m+1);
    sort(q.begin()+1,q.end(),[&](pr a,pr b)
    {
        return a[0]>b[0];
    });
    int t=n;
    vector<pr> tmp;
    vector<int> pre;
    tmp.emplace_back(pr{-inf,n+1});
    pre.emplace_back(0);
    vector<pr> tmp2;
    vector<int> pre2;
    tmp2.emplace_back(pr{inf,n+1});
    pre2.emplace_back(0);
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        int tt=t;
        while(t>q[i][0])
        {
            while(1)
            {
                int pos=tmp.size()-1;
                if(tmp[pos][0]<val[t]) break;
                tmp.pop_back();
                pre.pop_back();
            }
            int tt=val[t]*(tmp.back()[1]-t);
            tmp.emplace_back(pr{val[t],t});
            pre.emplace_back(pre.back()+tt);
            --t;
        }
        t=tt;
        while(t>q[i][0])
        {
            while(1)
            {
                int pos2=tmp2.size()-1;
                if(tmp2[pos2][0]>(t-p[t])) break;
                tmp2.pop_back();
            }
            tmp2.emplace_back(pr{(t-p[t]),t});
            --t;
        }
        // for(auto [x,y,z]:tmp) cout<<x<<' '<<y<<'\n';

        int x=q[i][0],y=q[i][1];
        int t2=min(a[x],p[x-1]+1);
        int t1=min(y,p[x-1]+1);
        int vv=t1-t2;
        if(t1<=t2)
        {
            // cc[q[i][2]]=tot+(t1-t2)*nxt[x];
            int l=0,r=tmp2.size()-1,pos=0;
            while(l<=r)
            {
                if(tmp2[mid][0]>=x-t1) pos=mid,l=mid+1;
                else r=mid-1;
            }
            int len=tmp2[pos][1]-x;
            int ret=-(suf[x]-suf[tmp2[pos][1]])+(t1+t1+len-1)*len/2;

            cc[q[i][2]]=tot+ret;
        }
        else
        {
            int pos=upper_bound(tmp.begin(),tmp.end(),pr{vv,n+1})-tmp.begin()-1;
            int ret=pre[pos]+vv*(tmp[pos][1]-x);
            cc[q[i][2]]=tot+ret;
        }
    }
    for(int i=1;i<=m;++i) cout<<cc[i]<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}