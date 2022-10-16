#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=505;
const int M=6e6+6;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,ans,m,x,y;
int a[N];
int f[N];
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        rd(n);
        int x=1;
        while (x<=n) x*=2;
        cout<<x/2-1<<endl;
    }
}