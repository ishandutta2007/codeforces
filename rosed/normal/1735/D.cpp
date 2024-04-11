#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e18;
    void __init(int n=2000) {}
    inline void main()
    {
        int n,m;
        cin>>n>>m;
        vector a(n,vector<int>(m));
        vector<int> cnt(n);
        map<vector<int>,int> q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j) cin>>a[i][j];
            vector<int> tmp(m);
            for(int k=0;k<i;++k)
            {
                for(int j=0;j<m;++j)
                {
                    if(a[k][j]==a[i][j]) tmp[j]=a[i][j];
                    else
                    {
                        int x=a[k][j],y=a[i][j];
                        if(x>y) swap(x,y);
                        if(x==0&&y==1) tmp[j]=2;
                        if(x==1&&y==2) tmp[j]=0;
                        if(x==0&&y==2) tmp[j]=1;
                    }
                }
                if(q.find(tmp)!=q.end()&&q[tmp]<k)
                {
                    ++cnt[i];
                    ++cnt[k];
                    ++cnt[q[tmp]];
                } 
            }
            q[a[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=cnt[i]*(cnt[i]-1)/2;
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 n/2 -> (1,n/2),(1,n/2+1)
3,n/2+1 -> (1,n/2-1),(1,n/2+2);
3,n-3 -> (1,n-6)
4,n-4 -> (1,n-3)

*/