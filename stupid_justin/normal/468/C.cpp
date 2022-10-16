#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroi-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define int long long 
#define ri int
#define rd(x) x=read()
using namespace std;
const int N=18;
const int M=505;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int a,b=1e18+1;
int l,r;
inline int get(int x){if (x<10) return x;return x%10+get(x/10);}
signed main()
{
    rd(a);
    l=a-b%a*9%a*9%a;
    r=b+l-1;
    cout<<l<<" "<<r<<endl;
}