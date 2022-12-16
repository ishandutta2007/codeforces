#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,inf=2e9,mod=998244353;
    int n,m;
    char s[N],t[N];
    struct node
    {
        int l,r;
    }a[N],b[N];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n;
            cin>>(s+1);
            cin>>(t+1);
            int s1=0,s2=0;
            s[n+1]=t[n+1]=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='1'&&s[i-1]!='1')
                {
                    ++s1;
                    a[s1].l=i;
                }
                if(s[i]=='1'&&s[i+1]!='1') a[s1].r=i;
                if(t[i]=='1'&&t[i-1]!='1')
                {
                    ++s2;
                    b[s2].l=i;
                }
                if(t[i]=='1'&&t[i+1]!='1') b[s2].r=i;
            }
            if(s1!=s2||s[1]!=t[1]||s[n]!=t[n])
            {
                cout<<"-1\n";
                continue;
            }
            int sum=0;
            for(int i=1;i<=s1;++i)
            {
                sum+=abs(a[i].l-b[i].l)+abs(a[i].r-b[i].r);
                //sum+=abs(a[i].l-b[i].l)-(a[i].l<b[i].l);
                //sum+=abs(a[i].r-b[i].r)-(a[i].r>b[i].r);
                //cout<<a[i].l<<' '<<a[i].r<<' '<<b[i].l<<' '<<b[i].r<<"!!"<<endl;
                //cout<<sum<<"!!"<<endl;
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
8
00010010
01011100



*/