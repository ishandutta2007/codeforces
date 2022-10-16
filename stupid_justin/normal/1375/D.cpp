#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=105;
const int M=1e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244853;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,mex;
vector<int> ans;
int a[M],v[M];
void DOIT()
{
    ans.clear();
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    while (1)
    {
        bool flag=1;
        for (int i=1;i<=n;i++) if (a[i]!=i-1) flag=0;
        if (flag) {cout<<ans.size()<<"\n";for (int x:ans) cout<<x<<" ";cout<<"\n";return;}
        for (int i=0;i<=n;i++) v[i]=0;
        for (int i=1;i<=n;i++) v[a[i]]=1;
        for (int i=0;i<=n;i++) if (!v[i]) {mex=i;break;}
        if (mex==n) {for (int i=1;i<=n;i++) if (a[i]!=i-1) {a[i]=n,ans.push_back(i);break;}}
        else a[mex+1]=mex,ans.push_back(mex+1);
    }
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();

}
/*
*/