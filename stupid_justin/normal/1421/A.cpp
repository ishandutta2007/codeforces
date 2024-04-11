#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=a;i<=b;++i)
#define req(i,a,b) for (register int i=a;i>=b;--i)
using namespace std;
int T,a,b,ans,p;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        p=ans=0;
        while(a>0||b>0)
        {
            ans+=((a&1)^(b&1))<<p;
            a>>=1;
            b>>=1;
            p++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}