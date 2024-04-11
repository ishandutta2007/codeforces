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
    const int N=1e6+10,mod=998244353,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;cin>>n;
        vector<int> a(n);
        vector<bool> vis(n,0);
        vector<vector<int> > t(n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;;++j)
            {
                if(j*j<i) continue;
                if(j*j-i>=n) break;
                t[i].emplace_back(j*j-i);
            }
        }
        //for(int i=0;i<n;++i) sort(f.begin(),f.end());
        bool flag=0;
        for(int i=n-1;i>=0;--i)
        {
            int tmp=i,pos=-1;
            //cout<<tmp<<"!!"<<endl;
            for(int i=(int)(t[tmp].size()-1);i>=0;--i) if(!vis[t[tmp][i]])
            {
                //cout<<tmp<<' '<<i<<' '<<t[tmp][i]<<' '<<vis[t[tmp][i]]<<"!!"<<endl;
                pos=t[tmp][i];
                break;
            }
            if(pos==-1)
            {
                flag=1;break;
            }
            a[pos]=i;
            vis[pos]=1;
        }
        if(flag) cout<<"-1\n";
        else for(int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/