#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n;
    int a[N],b[N],c[N],d[N];
    vector<int> pos[N];
    int num[N];
    typedef pair<int,int> pr;
    struct seg
    {
        int ans[N<<2];
        inline void build(int l,int r,int p)
        {
            if(l==r)
            {
                ans[p]=a[l];
                return;
            }
            build(l,mid,ls(p));
            build(mid+1,r,rs(p));
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        }
        inline void update(int pos,int l,int r,int p,int k)
        {
            if(l==r) {ans[p]=k;return;}
            if(pos<=mid) update(pos,l,mid,ls(p),k);
            else update(pos,mid+1,r,rs(p),k);
            ans[p]=min(ans[ls(p)],ans[rs(p)]);
        }
        inline int query(int tl,int tr,int l,int r,int p)
        {

            if(tl<=l&&r<=tr) return ans[p];
            int minn=inf;
            if(tl<=mid) minn=min(minn,query(tl,tr,l,mid,ls(p)));
            if(tr>mid) minn=min(minn,query(tl,tr,mid+1,r,rs(p)));
            return minn;
        }
    }T;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                pos[i].clear();
                num[i]=0;
            }
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                c[i]=a[i];
                pos[a[i]].emplace_back(i);
            }
            for(int i=1;i<=n;++i)
            {
                cin>>b[i];
                d[i]=b[i];
            }
            sort(c+1,c+n+1);sort(d+1,d+n+1);
            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                if(c[i]!=d[i])
                {
                    flag=1;
                }
            }
            if(flag)
            {
                cout<<"NO\n";
                continue;
            }
            T.build(1,n,1);
            for(int i=1;i<=n;++i)
            {
                int r=pos[b[i]][num[b[i]]++];
                int tmp=T.query(1,r,1,n,1);
               // cout<<r<<' '<<tmp<<"!!"<<endl;
                if(tmp==b[i])
                {
                    T.update(r,1,n,1,inf);
                }
                else flag=1;
            }
            if(flag) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
1
6
9 3 2 5 6 1
2 3 1 5 6 9


2 3 9 5 6 1

2 3 1 5 6 9


1-3,3-6,1-6

2-6,3-2,4-3,5-4,6-5

*/