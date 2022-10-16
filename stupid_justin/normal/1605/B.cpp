#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=1005;
const int mod=1e9+7;
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
int n;
string s;
vector<vector<int> > ans;
int suf[N],pre[N];
void solve()
{
	suf[n+1]=pre[0]=0;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='1');
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+(s[i]=='0');
	for (int i=1;i<=n;i++) if (pre[i]==suf[i+1])
	{
		vector<int> res;res.clear();
		for (int j=1;j<=i;j++) if (s[j]=='1') res.push_back(j);
		for (int j=i+1;j<=n;j++) if (s[j]=='0') res.push_back(j);
		ans.push_back(res);
		for (int j=0;j<res.size()/2;j++) swap(s[res[j]],s[res[res.size()-j-1]]);
		return;
	}
}
void DOIT()
{
	rd(n);cin>>s;s=" "+s;ans.clear();
	while (1)
	{
		bool flag=0;for (int i=1;i<n;i++) if (s[i]=='1' && s[i+1]=='0') flag=1;
		if (flag==0) break;solve();
	}
	cout<<ans.size()<<"\n";
	for (auto v:ans){cout<<v.size()<<" ";for (int x:v) cout<<x<<" ";cout<<"\n";}



}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
//qwq