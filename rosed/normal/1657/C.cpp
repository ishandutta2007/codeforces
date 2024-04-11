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
    const int N=5e5+10,mod=998244353,inf=2e9;
    int n,tot,pos;
    char s[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;
            cin>>(s+1);
            tot=0;pos=0;
            for(int i=1;i<=n;++i)
            {
                //cout<<i<<"!!"<<endl;
                if(i==n) break;
                if(s[i]==')'&&s[i+1]=='(')
                {
                    int p=0;
                    for(int j=i+2;j<=n;++j)
                    {
                        if(s[j]==')')
                        {
                            p=j;break;
                        }
                    }
                    if(!p) break;
                    else
                    {
                        ++tot;
                        i=p;
                    }
                }
                else
                {
                    ++tot;
                    ++i;
                }
                pos=i;
            }
            cout<<tot<<' '<<n-pos<<'\n';
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