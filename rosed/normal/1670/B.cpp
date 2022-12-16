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
    const int N=5e5+10,mod=1e9+7,inf=2e9;
    int n,m;
    int a[N];

    bool b[N];
    char s[N];
    bool vis[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            cin>>(s+1);
            for(int i=1;i<=n;++i) b[i]=0;
            cin>>m;
            for(int i=0;i<26;++i) vis[i]=0;
            for(int i=1;i<=m;++i)
            {
                char x;cin>>x;
                vis[x-'a']=1;
            }

            int pos=0,sum=0,tot=0;
            for(int i=1;i<=n;++i)
            {
                if(vis[s[i]-'a']) b[i]=1,pos=i;
            }
            if(!pos)
            {
                cout<<"0\n";
                continue;
            }
            int pre=pos;
            for(int i=pos-1;i>=1;--i)
            {
                //cout<<i<<' '<<tot<<"!!!!"<<endl;
                if(tot) --tot;
                else ++sum;
                if(b[i])
                {
                    tot+=pre-i;
                    pre=i;
                    //cout<<i<<' '<<pre-i<<"!!"<<endl;
                }
            }
            cout<<sum<<'\n';
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
13
acbaewrbadbad
2 d b


abaewbbd
baed
bad
bd
d
*/