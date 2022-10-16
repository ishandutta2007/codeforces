#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=5000+5;
const int M=1e9;
const int SZ=550;
const double eps=1e-9;
const int mod=998244853;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,cnt,tot;
int a[N];
signed main()
{
    rd(n);rd(m);
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (i+j<=n) tot++;
    if (tot<m) {puts("-1");return 0;}
    for (int i=n;i>=1;i--)
    {
        if (tot-m>=(i-1)/2) a[i]=M-3*(n-i+1)*n,tot-=((i-1)/2);
        else {a[i]+=2*(tot-m);break;}
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;

}
/*
*/