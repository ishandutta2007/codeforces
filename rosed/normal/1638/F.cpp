#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e4+10,mod=1e9+7,inf=2e9;
    int n,ans;
    int a[N];
    int pre[N],suf[N];
    int minn[N];
    int tmp[N];
    signed tl[N],tr[N],st[N],top;
    inline void work(int l,int r)
    {
        top=0;
        for(int i=l;i<=r;++i)
        {
            while(top&&a[st[top]]>a[i])
            {
                tr[st[top--]]=i;
            }
            st[++top]=i;
        }
        while(top) tr[st[top--]]=r+1;
        for(int i=r;i>=l;--i)
        {
            while(top&&a[st[top]]>a[i])
            {
                tl[st[top--]]=i;
            }
            st[++top]=i;
        }
        while(top) tl[st[top--]]=l-1;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i)
        {
            int minn=a[i];
            for(int j=i;j<=n;++j)
            {
                minn=min(minn,a[j]);
                pre[j+1]=max(pre[j+1],minn*(j-i+1));
                suf[i]=max(suf[i],minn*(j-i+1));
            }
        }
        for(int i=0;i<=n+1;++i)
        {
            for(int j=i;j<=n;++j)
            {
                ans=max(ans,pre[i]+suf[j]);
            }
        }
        work(1,n);
        for(int i=1;i<=n;++i)
        {
            int l=tl[i]+1,r=tr[i]-1;
            minn[l]=a[l];
            for(int j=l+1;j<=n;++j) minn[j]=min(minn[j-1],a[j]);
            for(int j=n;j>r;--j) tmp[j]=max(minn[j]*(j-l+1),tmp[j+1]);
            minn[r]=a[r];
            for(int j=r-1;j>=1;--j) minn[j]=min(minn[j+1],a[j]);
            for(int j=1;j<l;++j) tmp[j]=max(minn[j]*(r-j+1),tmp[j-1]);
            int t1=n,qaq=a[i];
            int t2=r;
            minn[l]=a[l];
            for(int j=l+1;j<=n;++j) minn[j]=min(minn[j-1],a[j]);
            for(int j=l-1;j>=1;--j)
            {
                if(a[j]<qaq) qaq=a[j];
                while(t1>r&&minn[t1]+qaq<a[i]) --t1;
                ans=max(ans,qaq*(r-j+1)+tmp[t1+1]);
                ans=max(ans,qaq*(r-j+1)+(a[i]-qaq)*(t1-l+1));
                while(t2<n&&a[t2+1]>=qaq) ++t2;
                ans=max(ans,qaq*(l-j+t2-r)+a[i]*(r-l+1));
            }

            minn[r]=a[r];
            for(int j=r-1;j>=1;--j) minn[j]=min(minn[j+1],a[j]);
            t1=1,t2=l,qaq=a[i];
            for(int j=r+1;j<=n;++j)
            {
                if(a[j]<qaq) qaq=a[j];
                while(t1<l&&minn[t1]+qaq<a[i]) ++t1;
                ans=max(ans,qaq*(j-l+1)+tmp[t1-1]);
                ans=max(ans,qaq*(j-l+1)+(a[i]-qaq)*(r-t1+1));
                while(t2>1&&a[t2-1]>=qaq) --t2;
                ans=max(ans,qaq*(j-r+l-t2)+a[i]*(r-l+1));
            }
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*

*/