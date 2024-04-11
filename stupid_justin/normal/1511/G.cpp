#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=2e5+5;
const int M=6e6+6;
const int SZ=450;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,m,q,l,r;
signed main()
{
    rd(n);rd(m);
    vector<int> a(n);
    for (int i=0;i<n;i++) rd(a[i]);
    sort(a.begin(),a.end());
    rd(q);
    while (q--)
    {
        rd(l);rd(r);
        int L=lower_bound(a.begin(),a.end(),l)-a.begin();
        int R=upper_bound(a.begin(),a.end(),r)-a.begin();
        int sg=0;
        for (int i=L;i<R;i++) sg^=a[i]-l;
        putchar("AB"[sg==0]);
    }
}