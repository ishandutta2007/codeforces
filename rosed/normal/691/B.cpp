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
        string t=s;
        reverse(t.begin(),t.end());
        bool flag=1;
        for(int i=0;i<n;++i)
        {
            char a=s[i],b=t[i];
            if(a=='x'&&b=='x') continue;
            if(a=='X'&&b=='X') continue;
            if(a=='o'&&b=='o') continue;
            if(a=='O'&&b=='O') continue;
            if(a=='T'&&b=='T') continue;
            if(a=='H'&&b=='H') continue;
            if(a=='A'&&b=='A') continue;
            if(a=='I'&&b=='I') continue;
            if(a=='M'&&b=='M') continue;
            if(a=='U'&&b=='U') continue;
            if(a=='v'&&b=='v') continue;
            if(a=='V'&&b=='V') continue;
            if(a=='W'&&b=='W') continue;
            if(a=='w'&&b=='w') continue;
            if(a=='Y'&&b=='Y') continue;
            if(a=='b'&&b=='d') continue;
            if(a=='d'&&b=='b') continue;
            if(a=='p'&&b=='q') continue;
            if(a=='q'&&b=='p') continue;
            flag=0;break;
        }
        if(flag) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    red::__init();
    int qwq=1; //cin>>qwq;
    while(qwq--) red::main();
    return 0;
}
/*

*/