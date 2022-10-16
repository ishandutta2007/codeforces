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
const int N=2e6+5;
const int M=2e5+5;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,k,ans,s,tmp;
multiset<int> S;
int a[N];
void DOIT()
{
    rd(s);rd(n);tmp=0;S.clear();
    if (n==1) {cout<<s<<endl;return;}
    for (int i=0,t=1;i<=9;i++,t*=10)
    {
        if (t!=1) for (int j=1;j<=(s/t)%10;j++) S.insert(t);
        else tmp+=(s/t)%10;
    }
    while (S.size()+tmp<n)
    {
        int x=(*S.begin());
        if (x==10) tmp+=10;else for (int i=1;i<=10;i++) S.insert(x/10);
        S.erase(S.find(x));
    }
    for (int i=1;i<=tmp;i++) S.insert(1);
    while (S.size()>n)
    {
        auto i=S.rbegin(),j=S.rbegin();i--;
        int x=(*i)+(*j);int y=*i,z=*j;
        S.erase(S.find(y));S.erase(S.find(z));S.insert(x);
    }
    for (int x:S) cout<<x<<" ";cout<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}