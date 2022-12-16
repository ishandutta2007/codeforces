#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-15)
    const int N=8e5+10,inf=2e9,mod=998244353,g=3,gi=332748118;
    int n,m;
    struct node
    {
        int pos,num;
    }a[N];
    map<int,int> q;
    int c[N],num;
    int s[N];
    int t1[N],t2[N];
    int pre[N],suf[N];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int qwq;cin>>qwq;
        //b[i] ib[i]
        while(qwq--)
        {
            cin>>n>>m;
            q.clear();
            num=0;
            for(int i=1;i<=n;++i)
            {
                cin>>a[i].pos>>a[i].num;
                ++q[a[i].pos-a[i].num];
                q[a[i].pos]-=2;
                ++q[a[i].pos+a[i].num];
                c[++num]=a[i].pos-a[i].num;
                c[++num]=a[i].pos;
                c[++num]=a[i].pos+a[i].num;
            }
            sort(c+1,c+num+1);
            num=unique(c+1,c+num+1)-c-1;
            for(int i=0;i<=num+1;++i) s[i]=0,pre[i]=suf[i]=t1[i]=t2[i]=-inf;
            for(int i=2,ss=0;i<=num;++i)
            {
                ss+=q[c[i-1]];
                s[i]=s[i-1]+ss*(c[i]-c[i-1]);
                if(s[i]>m)
                {
                    int tmp=max(0ll,s[i]-m);
                    t1[i]=tmp-c[i];
                    t2[i]=tmp+c[i];
                }
            }
            for(int i=1;i<=num;++i) pre[i]=max(pre[i-1],t1[i]);
            for(int i=num;i>=1;--i) suf[i]=max(suf[i+1],t2[i]);
            for(int i=1;i<=n;++i)
            {
                int p=a[i].pos,v=a[i].num;
                int t=lower_bound(c+1,c+num+1,p)-c;
                //cout<<t<<"!!"<<endl;
                //cout<<pre[t-1]<<' '<<suf[t]<<"!!"<<endl;
                if((pre[t-1]!=-inf&&v-p<pre[t-1])||(suf[t]!=-inf&&v+p<suf[t])) cout<<0;
                else cout<<1;
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
1
3 6
1 5
5 5
3 4

1
2 3
1 3
5 2


*/