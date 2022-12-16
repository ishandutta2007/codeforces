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
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n;
    int a[N];
    int ans=inf*inf;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T=1;
        while(T--)
        {
            cin>>n;
            // int l=1,r=2000,maxn=r;
            // while(l<=r)
            // {
            //     cout<<"? "<<mid<<endl;
            //     int x;cin>>x;
            //     if(x>0) ans=min(ans,mid*x);
            //     if(x>0) maxn=mid,r=mid-1;
            //     else l=mid+1;
            //     //cout<<ans<<"------"<<endl;
            // }
            //cout<<maxn<<"!!!!!!!!"<<endl;
            int tot=0;
            int l=2*n-1,r=2*2000*n+(n-1);
            int sum=r;
            while(l<=r)
            {
                cout<<"? "<<mid<<endl;
                int x;cin>>x;
                if(x>0) ans=min(ans,mid*x);
                if(x==1) sum=mid,r=mid-1;
                else l=mid+1; 
                //cout<<ans<<"-------"<<endl;
            }
            //cout<<maxn<<' '<<sum<<' '<<ans<<"!!!"<<endl;
            int t=2,c=(ans-1)/t;
            for(int i=2;i<=n;++i)
            {
                int tmp=ans/i;
                cout<<"? "<<tmp<<endl;
                int x;cin>>x;
                if(x>0)
                {
                    ans=min(ans,x*tmp);
                }
            }
            cout<<"! "<<ans<<endl;
            //cout<<ans<<' '<<sum<<"!!"<<endl;
            // while(c>0&&ans>sum-(n-1))
            // {
            //     cout<<"? "<<c<<endl;
            //     int x;cin>>x;
            //     if(!x) break;
            //     ans=min(ans,x*c);
            //     if(x==t) --c;
            //     else t=x,c=(ans-1)/t;
            // }
            // cout<<"! "<<ans<<endl;
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
5
1 2
2 3
3 4
3 5

*/