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
        vector<int> a(n);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        __int128 tmp=((__int128)(n-2))*sum;
        if(tmp%n)
        {
            cout<<"0\n";
            return;
        }
        tmp=sum-tmp/n;
        map<int,int> q;
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            cnt+=q[tmp-a[i]];
            ++q[a[i]];
        }
        cout<<cnt<<'\n';
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

2 2 2 4
10/4=5/2
sum/n=(sum-x)/(n-2)

n(sum-x)=(n-2)sum

*/