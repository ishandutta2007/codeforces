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
    const int N=1e6+10,mod=1e9+7,inf=2e15;
    void __init(int n=2000) {}
    inline void main()
    {
        string s1,s2;
        int p1,p2;
        cin>>s1>>p1>>s2>>p2;
        //while(p1--) s1+='0';
        //while(p2--) s2+='0';
        int n=s1.length(),m=s2.length();
        if(n+p1<m+p2) cout<<"<\n";
        else if(n+p1>m+p2) cout<<">\n";
        else
        {
            while(n<m) s1+='0',++n;
            while(m<n) s2+='0',++m;
            if(s1<s2) cout<<"<\n";
            else if(s1>s2) cout<<">\n";
            else cout<<"=\n";
        }
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
1 2 5 10

*/