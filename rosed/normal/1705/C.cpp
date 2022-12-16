#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=2e5+10,inf=1e18,mod=998244353;
    int n,m,k;
    char s[N];
    struct node
    {
        int l,r;
    }a[N];
    int pre[N];
    inline char find(int pos,int t)
    {
        //cout<<pos<<' '<<t<<"!!"<<endl;
        if(!t) return s[pos];
        int tl=a[t].l,tr=a[t].r;
        int dpos=a[t].l+pos-pre[t-1]-1;
       //cout<<pos<<' '<<dpos<<"!!"<<endl;
        int tpos=lower_bound(pre,pre+k+1,dpos)-pre;
        return find(dpos,tpos);
    }
    inline void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int qwq;cin>>qwq;
        while(qwq--)
        {
            cin>>n>>k>>m;
            cin>>(s+1);
            pre[0]=n;
            for(int i=1;i<=k;++i)
            {
                cin>>a[i].l>>a[i].r;
                pre[i]=pre[i-1];
                if(pre[i]<=inf) pre[i]+=a[i].r-a[i].l+1;
            }
            for(int i=1;i<=m;++i)
            {
                int pos;cin>>pos;
                int t=lower_bound(pre,pre+k+1,pos)-pre;
                cout<<find(pos,t)<<'\n';
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


a a b

t=b-a;

3 4 5
3 3 4
2 3 3
2 2 2

2 4 4

*/