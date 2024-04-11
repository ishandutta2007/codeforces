
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
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,q;
int p[N],S[26][N];
string s0,t,w;
vector<string>a;
vector<int> kmp(string &s)
{
	int n=s.size();
	vector<int>f(n,0);
	for (int i=1,j=0;i<n;i++)
	{
		while(j && s[j]!=s[i]) j=f[j-1];
		if (s[j]==s[i]) j++;f[i]=j;
	}
	return f;
}
vector<int> sol(vector<int>&f,int n)
{
	vector<int>a(n+1,0);
	int p=f.back();
	while(p) a[p]=1,p=f[p-1];
	a[p]=1;return a;
}
void DOIT()
{
	rd(k);cin>>w;
	m=w.size();
	int r=0;while (a[r].size()<m) r++;
	if (r>k){puts("0");return;}
	string s1=w+"$"+a[r],s2=a[r]+"$"+w;
	vector<int> f1=kmp(s1),f2=kmp(s2),v1=sol(f1,m),v2=sol(f2,m);
	int ans=0;for (int v:f1) if (v==m) ans++;ans=ans*p[k-r]%mod;
	for (int i=0;i<m;i++)
	{
		if (!v1[i] || !v2[m-i-1]) continue;
		int x=w[i]-'a';
		ans=(ans+S[x][k])%mod;
		ans=(ans-S[x][r]*p[k-r])%mod;
	}
	cout<<(ans+mod)%mod<<endl;
}
signed main()
{
	rd(n);rd(q);cin>>s0>>t;
	a.push_back(s0);
	for (char c:t)
	{
		if (a.back().size()>=1e6) break;
		string la=a.back();
		a.push_back(la+c+la);
	}
	for (int i=0;i<26;i++) for (int j=0;j<n;j++) S[i][j+1]=(S[i][j]*2+(t[j]-'a'==i))%mod;
	p[0]=1;for (int i=1;i<=n;i++) p[i]=p[i-1]*2%mod;
	while(q--) DOIT();
	
}
/*

*/