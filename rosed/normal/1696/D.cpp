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
    const int N=1e6+10,inf=2e9;
    int n,m,ans;
    int a[N],p[N];
    int tr[N][2];
    int st[N][2];
    int top[2];
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int skx;
        cin>>skx;
        while(skx--)
        {
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i];
                while(top[0]>0&&a[st[top[0]][0]]<a[i])
                {
                    tr[st[top[0]--][0]][0]=i;
                }
                while(top[1]>0&&a[st[top[1]][1]]>a[i])
                {
                    tr[st[top[1]--][1]][1]=i;
                }
                st[++top[0]][0]=i;
                st[++top[1]][1]=i;
            }
            //cout<<top[0]<<' '<<top[1]<<"!!"<<endl;
            while(top[0]) tr[st[top[0]--][0]][0]=n+1;
            while(top[1]) tr[st[top[1]--][1]][1]=n+1;
            int pos=1,len=0;
            while(pos<n)
            {
               // cout<<pos<<"!!!!!!!!!!!!!!!!!!!!!!"<<endl;
               // cout<<tr[pos][0]<<"!!!"<<endl;
                int r1=tr[pos][0];
                int p1=pos;
                while(tr[p1][1]<r1) p1=tr[p1][1];
                int r2=tr[pos][1];
                int p2=pos;
                while(tr[p2][0]<r2) p2=tr[p2][0];
               // cout<<r1<<' '<<r2<<"!!"<<endl;
               // cout<<pos<<' '<<p1<<' '<<p2<<"!!"<<endl;
                pos=max(p1,p2);
                ++len;
            }
            cout<<len<<'\n';
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
2 1 5 3 4

*/