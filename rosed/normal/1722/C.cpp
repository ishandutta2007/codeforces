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
        int n;cin>>n;
        vector<int> f(3);
        map<string,int> q;
        map<string,bool> a,b,c;
        string s;
        for(int i=0;i<n;++i) {cin>>s;++q[s];a[s]=1;}
        for(int i=0;i<n;++i) {cin>>s;++q[s];b[s]=1;}
        for(int i=0;i<n;++i) {cin>>s;++q[s];c[s]=1;} 
        for(auto [s,num]:q)
        {
            if(num==3) continue;
            if(num==2)
            {
                if(a[s]) ++f[0];
                if(b[s]) ++f[1];
                if(c[s]) ++f[2];
            }
            if(num==1)
            {
                if(a[s]) f[0]+=3;
                if(b[s]) f[1]+=3;
                if(c[s]) f[2]+=3;
            }
        }
        cout<<f[0]<<' '<<f[1]<<' '<<f[2]<<'\n';
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