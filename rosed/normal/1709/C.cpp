#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=998244353;
    int n,m;
    char s[N];
    int pre[N],suf[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>(s+1);
            n=strlen(s+1);
            if(n&1)
            {
                cout<<"NO\n";
                continue;
            }
            m=n/2;
            int sum=0,tot=0,ss=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='(') ++tot;
                pre[i]=pre[i-1];
                if(s[i]=='?') ++pre[i];
            }

            bool flag=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='(') ++sum;
                else if(s[i]==')') --sum;
                else
                {
                    if(sum==0||tot+pre[n]-pre[i-1]==m) ++sum,++tot;
                    else
                    {
                        --sum;
                        if(tot!=m) ++ss;
                    }
                }
                //cout<<sum<<"!!!!!"<<endl;
                if(sum<0)
                {
                    if(ss>0&&tot!=m) --ss,sum+=2,++tot;
                    else {flag=1;break;}
                }
               //cout<<sum<<"!!"<<endl;
            }
            //cout<<ss<<' '<<flag<<"!!"<<endl;
            if(flag||sum!=0||ss!=0) cout<<"NO\n";
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
(?)(?)

*/