#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    char ch,s[N];
    bool vis[26];
    vector<int> a;
    inline bool check(int l,int r)
    {
        cout<<"? 2 "<<l<<' '<<r<<endl;
        int x;cin>>x;
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(int i=l;i<r;++i)
        {
            if(!vis[s[i]-'a'])
            {
                vis[s[i]-'a']=1;
                ++sum;
            }
        }
        if(sum==x) return 1;
        return 0;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx=1;
        while(skx--)
        {
            cin>>n;
            cout<<"? 1 1"<<endl;
            cin>>s[1];
            for(int i=2;i<=n;++i)
            {
                a.clear();
                memset(vis,0,sizeof(vis));
                for(int j=i-1;j>=1;--j)
                {
                    if(!vis[s[j]-'a'])
                    {
                        vis[s[j]-'a']=1;
                        a.emplace_back(j);
                    }
                }
                reverse(a.begin(),a.end());
                int l=0,r=a.size()-1,pos=-1;
                while(l<=r)
                {
                    if(check(a[mid],i)) pos=mid,l=mid+1;
                    else r=mid-1;
                }
                if(pos==-1)
                {
                    cout<<"? 1 "<<i<<endl;
                    cin>>s[i];
                }
                else s[i]=s[a[pos]];
            }
            s[n+1]=0;
            cout<<"! "<<(s+1)<<endl;
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*


*/