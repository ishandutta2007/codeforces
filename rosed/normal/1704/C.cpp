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
    const int N=5e5+10,mod=1e9+7,inv2=5e8+4,inf=2e9;
    const double pi=acos(-1.0);
    int n,m;
    int a[N],b[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>a[i];
            }
            sort(a+1,a+m+1);
            int num=0;
            if(m==1) b[++num]=n-1;
            else
            {
                for(int i=2;i<=m;++i)
                {
                    b[++num]=a[i]-a[i-1]-1;
                }
                b[++num]=a[1]+n-a[m]-1;
                sort(b+1,b+num+1);
                reverse(b+1,b+num+1);
            }
            int tim=0,sum=m;
            for(int i=1;i<=num;++i)
            {
                int tmp=min(b[i],tim*2);
                sum+=tmp;
                b[i]-=tmp;
                if(b[i]==0) continue;
                if(b[i]<=2)
                {
                    if(b[i]==1) ++tim;
                    if(b[i]==2) ++tim,++sum;
                }
                else
                {
                    tim+=2;
                    ++sum;
                }
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
10 3
3 6 8

*/