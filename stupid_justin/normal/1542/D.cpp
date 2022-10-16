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

int n,ans;
int a[N];
string s;
int f[N];
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (s=="-") a[i]=-1;
        else rd(a[i]);
    }
    for (int i=1;i<=n;i++) if (a[i]>0)
    {
        //f[k]  a[i]  
        //
        f[0]=1;for (int j=1;j<=n;j++) f[j]=0;
        for (int j=1;j<i;j++)
        {
            if (a[j]==-1) {f[0]*=2;f[0]%=mod;for (int k=0;k<=n;k++) {f[k]+=f[k+1];f[k]%=mod;}}
            else if (a[j]<=a[i]) for (int k=n-1;k>=0;k--) {f[k+1]+=f[k];f[k+1]%=mod;}
            else if (a[j]>a[i]) for (int k=0;k<=n;k++) {f[k]*=2;f[k]%=mod;}
        }
        for (int j=i+1;j<=n;j++)
        {
            if (a[j]==-1) for (int k=0;k<=n;k++) {f[k]+=f[k+1];f[k]%=mod;}
            else if (a[j]<a[i]) for (int k=n-1;k>=0;k--) {f[k+1]+=f[k];f[k+1]%=mod;}
            else if (a[j]>=a[i]) for (int k=0;k<=n;k++) {f[k]*=2;f[k]%=mod;}
        }
        int x=0;for (int j=0;j<=n;j++) {x+=f[j];if (x>=mod) x-=mod;}
        //cout<<"x="<<x<<endl;
        ans+=a[i]*x%mod;if (ans>=mod) ans-=mod;
    }
    cout<<ans<<endl;
}