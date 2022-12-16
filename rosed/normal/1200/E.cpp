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
    const int N=2e6+10,mod=998244353,inf=2e9;
    int tot;
    int n,m;
    char s[N],t[N],a[N];
    int nxt[N];
    inline void getnxt(int n)
    {
        int t1=0,t2=-1;
        nxt[0]=-1;
        while(t1<n)
        {
            if(t2==-1||a[t1]==a[t2]) nxt[++t1]=++t2;
            else t2=nxt[t2];
        }
    }
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>tot;
        cin>>s;
        n=strlen(s);
        for(int op=1;op<tot;++op)
        {
            cin>>t;
            m=strlen(t);
            int len=min(n,m);
            int k=0;
            for(int i=n-1;i>=n-len;--i) a[k++]=s[i];
            a[k++]='#';
            for(int i=len-1;i>=0;--i) a[k++]=t[i];
            getnxt(k);
            int q=nxt[k];
            //cout<<k<<' '<<q<<"!!"<<endl;
            for(int i=q;i<m;++i) s[n++]=t[i];
        }
        for(int i=0;i<n;++i) cout<<s[i];
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