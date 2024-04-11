#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1005;
const int M=6e6+6;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,ans,m,x,y;
int a[N];
char ch[N];
int f[N][N][2][2],v[N][N][2][2];
int s(int k,int t,int o,int p)
{
    //k  00  t  01  0 
    if (v[k][t][o][p]!=0) return f[k][t][o][p];

    int ret=0;
    //  00  01
    // 
    // 
    if (k==0 && t==0 && o==0) ret=0; else
    {
        // 00   01  0 
        int s1=1005,s2=1005,s3=1005,s4=1005,s5=1005;
        if (k!=0) s1=1-s(k-1,t+1,o,0),s5=min(s5,s1);
        if (t!=0) s2=1-s(k,t-1,o,0),s5=min(s5,s2);
        if (o!=0) s3=1-s(k,t,0,0),s5=min(s5,s3);
        if (p!=1 && t!=0) s4=-s(k,t,o,1),s5=min(s5,s4);
        ret=s5;
    }
    v[k][t][o][p]=1;
    //printf("s(%lld,%lld,%lld,%lld)=%lld\n",k,t,o,p,ret);
    return f[k][t][o][p]=ret;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        rd(n);scanf("%s",ch+1);x=0;y=0;
        for (int i=1;i<=n;i++) a[i]=ch[i]-'0';
        //for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
        //cout<<"n="<<n<<endl;
        for (int i=1;i<=n/2;i++) if (a[i]!=a[n+1-i]) x++;else if (a[i]==0 && a[n+1-i]==0) y++;
        //x y
        int ans=s(y,x,(a[n/2+1]==0)&(n%2),0);
        if (ans>0) puts("BOB");else if (ans<0) puts("ALICE");else puts("DRAW");
    }
}
/*
00 00 00 00 00 00 00
01 01 01 01
*/