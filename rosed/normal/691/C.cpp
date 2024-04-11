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
        string ans;
        int n=s.length();
        int num=0;
        reverse(s.begin(),s.end());
        
        while(s.back()=='0'&&n>1) s.pop_back(),--n;
        reverse(s.begin(),s.end());
        if(s[0]=='.')
        {
            for(int i=0;i<n-1;++i)
            {
                if(s[i+1]=='0') swap(s[i],s[i+1]),--num;
                else break;
            }
        }
        
        reverse(s.begin(),s.end());
        
        while(s.back()=='0'&&n>1) s.pop_back(),--n;
        reverse(s.begin(),s.end());
        int pos=n;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='.')
            {
                pos=i;
            }
            else ans+=s[i];
        }
        if(pos!=n)  while(s.back()=='0'&&n>1) s.pop_back(),--n;
        if(ans=="") ans="0";
        int m=ans.length();
        while(ans.back()=='0'&&m>1) ans.pop_back(),--m;
        num+=pos-1;
        if(ans[0]=='0')
        {
            cout<<0;
            return;
        }
        cout<<ans[0];
        if(m>1)
        {
            cout<<'.';
            reverse(ans.begin(),ans.end());
            ans.pop_back();
            reverse(ans.begin(),ans.end());
            cout<<ans;
        }

        if(num) cout<<'E'<<num;
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