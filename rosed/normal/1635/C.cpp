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
    int n,sum;
    int a[N],maxn,minn,tmp;
    int pos1,pos2;
    bool flag;
    struct node
    {
        int x,y,z;
    }st[N];
    int top;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n;sum=0;flag=1;top=0;pos1=pos2=n;
            for(int i=1;i<=n;++i) cin>>a[i];
            maxn=minn=a[n];tmp=1e9+7;
            for(int i=n-1;i;--i)
            {
                if(a[i]>a[i+1])
                {
                    if(tmp>a[i+1])
                    {
                        flag=0;break;
                    }
                    a[i]=tmp;
                    st[++top]=(node){i,pos2,pos1};
                    ++sum;
                }
                if(a[i]-maxn<tmp) tmp=a[i]-maxn,pos2=i;
                if(a[i]>maxn) maxn=a[i],pos1=i;
            }
            if(!flag){cout<<"-1\n";continue;}
            else
            {
                cout<<sum<<'\n';
                for(int i=1;i<=top;++i) cout<<st[i].x<<' '<<st[i].y<<' '<<st[i].z<<'\n';
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
1
5
-2 -1 -5 4 5

*/