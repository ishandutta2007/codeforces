#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,mod=998244353,inf=2e9;
    int n,ql,qr,ans;
    int pre;
    int a[N];
    inline void work(int l,int r)
    {
        if(l>r) return;
        int sum=0,s2=0;
        for(int i=l;i<=r;++i)
        {
            if(a[i]<0) ++sum;
            if(abs(a[i])==2) ++s2;
        }
        if(sum%2==0)
        {
            if(s2>ans) ans=s2,ql=l-1,qr=n-r;
            return;
        }
        int tl=l-1,tr=r+1;
        int s=0,ss=0;
        while(1)
        {
            ++tl;
            s+=(abs(a[tl])==2);
            if(a[tl]<0) break;
        }
        while(1)
        {
            --tr;
            ss+=(abs(a[tr])==2);
            if(a[tr]<0) break;
        }
        if(s<ss) l=tl+1,s2-=s;
        else r=tr-1,s2-=ss;
        if(s2>ans) ans=s2,ql=l-1,qr=n-r;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            pre=1;ans=0;
            ql=n;qr=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                if(a[i]==0)
                {
                    work(pre,i-1);
                    pre=i+1;
                }
            }
            work(pre,n);
            cout<<ql<<' '<<qr<<'\n';
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
1 2 3 4

*/