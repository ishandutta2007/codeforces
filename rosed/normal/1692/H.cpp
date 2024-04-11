#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,mod=998244353,inf=2e9;
    int n,k;
    int a[N],c[N],num;
    vector<int> q[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            num=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                c[++num]=a[i];
            }
            sort(c+1,c+num+1);
            num=unique(c+1,c+num+1)-c-1;
            for(int i=1;i<=n;++i)
            {
                a[i]=lower_bound(c+1,c+num+1,a[i])-c;
                //cout<<a[i]<<"!!"<<endl;
                q[a[i]].emplace_back(i);
            }
            int ans=0,tot=0,tl=0,tr=0;
            for(int x=1;x<=num;++x)
            {
                int s=q[x].size(),minn=0,posl=q[x][0],pre=q[x][0]-1,sum=0;
                //cout<<x<<"!!"<<endl;
                for(int i=0;i<s;++i)
                {
                    int t=q[x][i];
                    //cout<<t<<"!!"<<endl;    
                    sum=sum-(t-pre-1)+1;
                    if(sum-1<minn) minn=sum-1,posl=t;
                    //cout<<c[x]<<' '<<sum<<"!!"<<endl;
                    int ret=sum-minn;
                    if(ret>tot)
                    {
                        tot=ret;
                        ans=c[x];
                        tl=posl,tr=t;
                    }
                    //if(sum<minn) minn=sum,posl=t;
                    pre=t;
                }
                q[x].clear();
            }
            cout<<ans<<' '<<tl<<' '<<tr<<'\n';
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
10
2 1 2 1 1 2 2 2 1 1

*/