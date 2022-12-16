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
    const int N=1e6+10,mod=1e9+7,inv2=5e8+4,inf=2e15;
    void __init(int n=2000) {}
    
    inline void main()
    {
        int n,sum=0;
        cin>>n;
        vector<int> a(n+1);
        priority_queue<int> q;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum+=a[i];
            q.push(a[i]);
        }
        vector<int> f(60),pre(60);
        f[0]=1,f[1]=1;
        pre[0]=1;
        int num=0;
        for(int i=0;i<=60;++i)
        {
            assert(i<=60);
            if(i>1) f[i]=f[i-1]+f[i-2];
            if(i>0) pre[i]=pre[i-1]+f[i];
            if(pre[i]>=sum)
            {
                num=i;break;
            }
        }
        if(pre[num]>sum)
        {
            cout<<"NO\n";return;
        }
        int lst=0;
        while(num>=0)
        {
            int now=q.top();
            q.pop();
            if(now<f[num])
            {
                cout<<"NO\n";
                return;
            }
            now-=f[num];
            q.push(lst);
            lst=now;
            --num;
        }
        cout<<"YES\n";
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

*/