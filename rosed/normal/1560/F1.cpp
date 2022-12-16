#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=1e5+10,inf=2e9;
    int n,m;
    int st[N],top;
    int ret[N];
    int tot;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;
            if(m==1)
            {
                int ans=1e12;
                int x=n;
                top=0;
                while(x) st[++top]=x%10,x/=10;
                reverse(st+1,st+top+1);
                for(int a=0;a<=9;++a)
                {
                    int num=0,flag=0,ok=1;
                    for(int i=1;i<=top;++i)
                    {
                        num=num*10+a;
                        if(st[i]>a&&!flag) ok=0;
                        if(st[i]<a) flag=1;
                    }
                    if(ok) ans=min(ans,num);
                }
                cout<<ans<<'\n';
            }
            else
            {
                int ans=1e12;
                int x=n;
                top=0;
                while(x) st[++top]=x%10,x/=10;
                reverse(st+1,st+top+1);
                for(int a=0;a<=9;++a)
                {
                    for(int b=a;b<=9;++b)
                    {
                        int num=0;
                        for(int l=0;l<=top;++l)
                        {
                            for(int r=l+1;r<=top;++r)
                            {
                                num=0;
                                bool qaq=0;
                                for(int i=1;i<=l;++i) {num=num*10+st[i];if(st[i]!=a&&st[i]!=b) qaq=1;}
                                    if(qaq) continue;
                                for(int i=l+1;i<=r;++i) num=num*10+b;
                                for(int i=r+1;i<=top;++i) num=num*10+a;
                                 //    if(l==0&&r==2&&a==1&&b==2) cout<<num<<"!!!"<<endl;
                                if(num>=n) ans=min(ans,num);
                            }
                        }
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
2
4626299 2
431761 2

*/