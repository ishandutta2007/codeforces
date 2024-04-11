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
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
vector<int> T[N];
int n,m;
int x,y;
signed main()
{
    int T;cin>>T;while (T--)
    {
        rd(n);x=y=0;
        for (int i=1,a;i<=2*n;i++) 
        {
            rd(a);if (a%2==0) x++;else y++;
        }
        if (x==y) puts("Yes");else puts("No");
    }
}
/*

*/