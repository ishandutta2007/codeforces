#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=5e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    struct node
    {
        int x,y,id;
        inline bool operator < (const node &t) const
        {
            return y<t.y;
        }
    }a[N];
    typedef pair<int,int> p;
    p st[N];
    int top;
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int T;cin>>T;
        while(T--)
        {
            cin>>n>>m;top=0;
            for(int i=1;i<=m;++i)
            {
                cin>>a[i].x>>a[i].y;
                a[i].id=i;
            }
            sort(a+1,a+m+1);
            int sum=0;
            for(int i=1;i<=2*n;++i)
            {
                st[++top]=p(a[i].x,a[i].id);
                sum+=a[i].y;
                //cout<<a[i].y<<"!!!!!!!!!"<<endl;
            }
            cout<<sum<<'\n';
            sort(st+1,st+top+1);
            for(int i=1;i<=n;++i)
            {
                cout<<st[i].second<<' '<<st[top-i+1].second<<'\n';
            }
            cout<<'\n';
        }
    }
}
signed main()
{
    red::main();
    return 0;   
}
/*
5 5
5 1 2
6 2 3
4 3 5
6 2 4
5 1 3

*/