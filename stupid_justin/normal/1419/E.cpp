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
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
set<int> S;
int n,u,k,p;
void DOIT()
{
    rd(n);u=n;k=p=0;S.clear();
    for (int i=2;i*i<=n;i++) if (n%i==0) S.insert(i),S.insert(n/i),k+=(i*i*i==n);
    if (S.size()==2 && k==0) cout<<*(S.begin())<<" ",S.erase(S.begin()),p=1;
    cout<<u<<" ";while (!S.empty()) for (int x:S) if (__gcd(u,x)!=1) {u=x;S.erase(u);cout<<u<<" ";break;}
    cout<<"\n"<<p<<"\n";
}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}