
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=1e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n;
int a[N];
int ask(int p){if (a[p]) return a[p];cout<<"? "<<p<<endl;cin>>a[p];return a[p];}
void solve(int l,int r)
{
    // a[l-1]>a[l],a[r]<a[r+1]
    if (r-l<=3) for (int i=l;i<=r;i++) if (ask(i-1)>ask(i) && ask(i)<ask(i+1)) {cout<<"! "<<i<<endl;exit(0);}
    int mid=(r+l)/2;if (ask(mid)<ask(mid+1)) solve(l,mid);else solve(mid+1,r);
}
signed main()
{
    cin>>n;a[0]=a[n+1]=n+1000;
    ask(1);ask(n);solve(1,n);

}
/*

*/