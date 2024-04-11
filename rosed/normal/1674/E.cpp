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
    int n,m,tot,ans;
    int a[N],b[N];
    inline int ceil(int x,int y)
    {
        if(x<=0) return 0;
        return (x-1)/y+1;
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n;
            ans=inf;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                b[i]=a[i];
            }
            sort(b+1,b+n+1);
            ans=(b[1]-1)/2+1+(b[2]-1)/2+1;
            for(int i=1;i+2<=n;++i)
            {
                int x=a[i],y=a[i+2];
                if(x>y) swap(x,y);
                ans=min(ans,x+ceil(y-x,2));
            }
            for(int i=1;i+1<=n;++i)
            {
                int x=a[i],y=a[i+1];
                if(x>y) swap(x,y);
                int tmp=(y-1)/2+1;
                x-=tmp;x=max(0ll,x);
                
                ans=min(ans,tmp+ceil(x,2));

                x=a[i],y=a[i+1];
                if(x>y) swap(x,y);
                tmp=(2*y-x)/3;
                //cout<<tmp<<"!!"<<endl;
                ans=min(ans,tmp+max(0ll,y-2*tmp));
            }
            cout<<ans<<'\n';
            // 11 9
            // 6+2
            // 5+
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
5
20 10 30 11 9

*/