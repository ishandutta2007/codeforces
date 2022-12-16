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
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>n;
        int x=0,y=0;
        bool flag=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            int tmp=abs(a[i]-a[i-1]);
            if(a[i]==a[i-1]&&i!=1) flag=1;
            if(i!=1&&tmp!=1)
            {
                if(y==0||tmp==y) y=tmp;
                else flag=1;
            }
        }
        if(!y) y=1e9;
        if(flag) {cout<<"NO\n";return;  }
        for(int i=2;i<=n;++i)
        {
            int tmp=abs(a[i]-a[i-1]);
            if(tmp!=1) continue;
            int t1=(a[i]-1)/y+1,t2=(a[i-1]-1)/y+1;
           // cout<<i<<' '<<t1<<' '<<t2<<"!!"<<endl;
            if(t1!=t2) flag=1;
        }
        x=1e9;
        if(flag) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            cout<<x<<' '<<y<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;
}
/*
6
2 3 4 6 8 10

*/