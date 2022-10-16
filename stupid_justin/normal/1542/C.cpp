#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=5e5+5;
const int M=6e6+6;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,m,x;
int ans;
int chk(int a)
{
    int ret=0;
    // x  a 
    if (a==4 || a==8 || a==16 || a==32) ret=a*(x-x/2)%mod,x/=2; else 
    if (a==9 || a==27) ret=a*(x-x/3)%mod,x/=3; else 
    if (a==25) ret=a*(x-x/5)%mod,x/=5; else 
    ret=a*(x-x/a)%mod,x/=a;
    return ret;
}
signed main()
{
    int T;cin>>T;while (T--)
    {
        rd(n);x=n;
        ans=0;
        ans+=chk(2);ans%=mod;
        ans+=chk(3);ans%=mod;
        ans+=chk(4);ans%=mod;
        ans+=chk(5);ans%=mod;
        ans+=chk(7);ans%=mod;
        ans+=chk(8);ans%=mod;
        ans+=chk(9);ans%=mod;
        ans+=chk(11);ans%=mod;
        ans+=chk(13);ans%=mod;
        ans+=chk(16);ans%=mod;
        ans+=chk(17);ans%=mod;
        ans+=chk(19);ans%=mod;
        ans+=chk(23);ans%=mod;
        ans+=chk(25);ans%=mod;
        ans+=chk(27);ans%=mod;
        ans+=chk(29);ans%=mod;
        ans+=chk(31);ans%=mod;
        ans+=chk(32);ans%=mod;
        ans+=chk(37);ans%=mod;
        ans+=chk(41);ans%=mod;
        cout<<ans<<endl;
    }
}
/*

32*27*25*7*11*13*17*19*23*29*31*37
...38
*/