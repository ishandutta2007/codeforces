
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
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=1e18;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m,k,ans,cnt;
unordered_map<int,int> Map;
int L(int x){for (int i=60;i>=0;i--) if (x>>i&1) return i;}
int G(int k){if (k==0) return 1;int t=(ksm(2,k,mod-1)-2+mod-1)%(mod-1);return ksm(4,t);}
bool chk(int x,int y){if (x==y || x+y==7) return 0;return 1;}
unordered_map<int,int> f[7];
unordered_map<int,int> v[7];
int F(int x,int y)
{
	if (v[y][x]) return f[y][x];
	int ret=0;
	if (!Map[x]) return G(k-L(x));
	if (Map[x]==7)
	{
		if (k-L(x)==1) return 1;
		for (int a=1;a<=6;a++) if (chk(a,y)) for (int b=1;b<=6;b++) if (chk(b,y)) ret=(ret+F(x*2,a)*F(x*2+1,b))%mod;
	} else 
	{
		if (Map[x]!=y) return 0;
		if (k-L(x)==1) return 1;
		for (int a=1;a<=6;a++) if (chk(a,y)) for (int b=1;b<=6;b++) if (chk(b,y)) ret=(ret+F(x*2,a)*F(x*2+1,b))%mod;
	}
	v[y][x]=1;
	return f[y][x]=ret;
}
char s[N];
void insert(int x,int c)
{
	if (x==0) return;
	if (Map[x]!=7 && Map[x]!=0 && Map[x]!=c && c!=7) {puts("0");exit(0);}
	if (!Map[x] || Map[x]==7) Map[x]=c;
	insert(x/2,7);
}
signed main()
{
	rd(k);rd(n);
	while (n--)
	{
		int x;rd(x);scanf("%s",s);
		if (s[0]=='w') insert(x,1);
		if (s[0]=='r') insert(x,2);
		if (s[0]=='g') insert(x,3);
		if (s[0]=='b') insert(x,4);
		if (s[0]=='o') insert(x,5);
		if (s[0]=='y') insert(x,6);
	}
	for (int i=1;i<=6;i++) ans+=F(1,i);
	cout<<ans%mod<<endl;
}