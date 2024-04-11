#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-15)
#define y1 uuuu
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int t1=0,t2=n-1,s1=0,s2=0;
        int lim1=n/2-1;
        int lim2=n/2;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='L') sum+=i;
            else sum+=n-i-1;
        }
        for(int i=1;i<=n;++i)
        {
            while(s[t1]=='R'&&t1<=lim1) ++t1,++s1;
            while(s[t2]=='L'&&t2>=lim2) --t2,++s2;
            if(t1>lim1&&t2<lim2)
            {
                cout<<sum<<' ';
                continue;
            }
            if(s1<=s2)
            {
                sum-=t1;
                sum+=n-t1-1;
                s[t1]='R';
            }
            else
            {
                sum-=n-t2-1;
                sum+=t2;
                s[t2]='L';
            }
            cout<<sum<<' ';
        }
        cout<<'\n';
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