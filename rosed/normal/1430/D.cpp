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
        int n;
        string s;
        cin>>n;
        cin>>s;
        // struct node
        // {
        //     int l,r,pos;
        // };
        int ans=0;
        int l=0,id=1,ret=0;
        for(int r=1;r<n;++r)
        {
            if(s[r]==s[l]) continue;
            else
            {
                ret+=min(max(0ll,r-l-1),max(0ll,id-ret));
                ++id;
                l=r;
            }
            //cout<<ans<<"!!"<<endl;
        }
        ret+=min(max(0ll,n-l-1),max(0ll,id-ret));
        cout<<min((id+1+ret)/2,id)<<'\n';
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