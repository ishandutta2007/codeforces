#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,inf=2e9,mod=1e9+7;
    int n,ans=1;
    int a[N],pos[N];
    set<int> q1,q2;
    inline void work(int l,int r)
    {
        while(!q2.empty())
        {
            auto it=q1.end();--it;
            int y=*it;
            int z=*(q2.begin());
            //cout<<y<<' '<<z<<"!!"<<endl;
            if(y==z-1)
            {
                ans=ans*(r-l+1-q1.size())%mod;
                q2.erase(z);
                q1.insert(z);
            }
            else break;
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            ans=1;
            q1.clear();q2.clear();
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                ++a[i];
                pos[a[i]]=i;
            }
            int l=pos[1],r=pos[1];
            q1.insert(1);
            for(int i=2;i<=n;++i)
            {
                int t=pos[i];
                if(l<=t&&t<=r)
                {
                    //ans=ans*(r-l+1-q1.size())%mod;
                    //q1.insert(i);
                    //ans=ans*(r-l+1-q1.size())%mod;
                    continue;
                }
                if(t<l)
                {
                    q1.insert(i);
                    for(int j=l-1;j>t;--j) q2.insert(a[j]);
                    l=t;
                    work(l,r);
                }
                else
                {
                    q1.insert(i);
                    for(int j=r+1;j<t;++j) q2.insert(a[j]);
                    r=t;
                    work(l,r);
                }
            }
            cout<<ans<<'\n';
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
1 2 4 0 5 3



1
5
0 2 1 3 4


*/