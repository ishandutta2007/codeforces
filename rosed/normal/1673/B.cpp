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
    const int N=1e6+10,mod=1e4+7,inf=2e9;
    int n,m;
    char s[N];
    int col;
    map<int,int> q;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>s;n=strlen(s);
            q.clear();
            int len=0;
            bool flag=0;
            for(int i=0;i<n;++i)
            {
                if(q[s[i]])
                {
                    if(q[s[i]]!=1) flag=1;
                    len=i;
                    break;
                }
                q[s[i]]=1;
            }
            for(int i=0;i<len;++i)
            {
                int j=i;
                while(j<n)
                {
                    if(s[i]!=s[j]) flag=1;
                    j+=len;
                }
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

*/