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
    const int N=1e6+10,mod=1e9+7,inv2=(mod+1)/2,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        string s;cin>>s;
        int n=s.length();
        int l=-1,r=-1;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='a')
            {
                l=r=i;break;
            }
        }
        if(l==-1)
        {
            cout<<"NO\n";
            return;
        }
        for(int c=1;c<n;++c)
        {
            if(l!=0&&s[l-1]-'a'==c){--l;continue;}
            if(r!=n-1&&s[r+1]-'a'==c){++r;continue;}
            cout<<"NO\n";
            return;
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