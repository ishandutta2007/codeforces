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
    const int N=1e6+10,mod=998244353,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        typedef array<int,2> pr;
        vector<pr> a(n);
        vector<int> c1(n+1),c2(n+1);
        int sum1=0,sum2=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i][0]>>a[i][1];
            ++c2[a[i][1]];
            ++sum2;
        }
        sort(a.begin(),a.end());
        int cnt=0,ret=0,ans=0;
        for(int i=0;i<n;)
        {
            int j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j)
            {
                ret-=sum1-c1[a[j][1]];
                --c2[a[j][1]];
                --sum2;
            }
            j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j)
            {
                cnt+=ret;
                cnt-=c1[a[j][1]]*(sum2-c2[a[j][1]]);
                cnt-=c2[a[j][1]]*(sum1-c1[a[j][1]]);
            }
            j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j)
            {
                ret+=sum2-c2[a[j][1]];
                ++c1[a[j][1]];
                ++sum1;
            }

            i=j;
            //cout<<i<<' '<<cnt<<"!!"<<endl;
        }
        ans-=cnt;
        for(int i=0;i<n;)
        {
            int j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j);
            int t=j;
            j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j)
            {
                ans+=(i)*(n-t);
            }
            i=j;
            //cout<<i<<' '<<cnt<<"!!"<<endl;
        }
        //cout<<ans<<"!!!!"<<endl;
        for(int i=0;i<n;++i) swap(a[i][0],a[i][1]);
        sort(a.begin(),a.end());
        for(int i=0;i<n;)
        {
            int j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j);
            int t=j;
            j=i;
            for(;a[i][0]==a[j][0]&&j<n;++j)
            {
                ans+=(i)*(n-t);
            }
            i=j;
            //cout<<i<<' '<<cnt<<"!!"<<endl;
        }
        cout<<ans<<'\n';
        //cout<<ans/4<<'\n';
        //cout<<cnt<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*
1 7 5 6 8 2 6 5

0 8 5 6 8 0 8 5
3
5 6 5
3 8 5
2
3
8
*/