/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
#define poly vector <int>
#define len(x) (int)x.size()
using namespace std;
const int N=8*1e5+100;
int n,k,rev[N],len,Inv[N];
string s[N];
vector <int> w[25];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	int d=20;
	for (int i=1;i<=d;i++)
	{
		w[i].resize(1<<i);
		w[i][0]=1;w[i][1]=m_pow(3,(mod-1)>>i);
		for (int j=2;j<(1<<i);j++) w[i][j]=w[i][j-1]*w[i][1]%mod;
	}
}
poly operator +(poly a,poly &b)
{
	a.resize(max(len(a),len(b)));
	for (int i=0;i<len(b);i++) add(a[i],b[i]);
	return a;
}
poly operator -(poly a,poly &b)
{
	a.resize(max(len(a),len(b)));
	for (int i=0;i<len(b);i++) del(a[i],b[i]);
	return a;
}
inline void integ(poly &y)
{
	for (int i=len(y)-2;i>=0;i--) y[i+1]=y[i]*Inv[i+1]%mod;
	y[0]=0;
}
inline void der(poly &y)
{
	for (int i=1;i<len(y);i++) y[i-1]=y[i]*i%mod;
	y[len(y)-1]=0;
}
inline void change(int len)
{
	for (int i=0;i<len;i++)
	{
		rev[i]=rev[i>>1]>>1;
		if (i&1) rev[i]|=(len>>1);
	}
}
inline void DFT(poly &y,int len,int v)
{
	for (int i=0;i<len;i++) if (i<rev[i]) swap(y[i],y[rev[i]]);
	for (int i=1,d=1;i<len;i<<=1,d++)
	{
		for (int j=0;j<len;j+=(i<<1))
		{
			int *W=&w[d][0],a,b;
			for (int k=j;k<j+i;k++)
			{
				a=y[k],b=y[k+i]*(*W++)%mod;
				y[k]=y[k+i]=a;
				add(y[k],b);del(y[k+i],b);
			}
		}
	}
	if (v==-1)
	{
		reverse(y.begin()+1,y.end());
		int invlen=m_pow(len,mod-2);
		for (int i=0;i<len;i++) mul(y[i],invlen);
	}
}
poly operator *(poly a,poly b)
{
	if (a.empty()) return b;
	if (b.empty()) return a;
	int n=len(a),m=len(b);
	len=1;while(len<n+m)len<<=1;change(len);
	a.resize(len);b.resize(len);
	DFT(a,len,1);DFT(b,len,1);
	for (int i=0;i<len;i++) mul(a[i],b[i]);
	DFT(a,len,-1);a.resize(n+m-1);
	return a;
}
poly solve(int l,int r)
{
	if (l==r)
	{
		poly ans;
		if (s[l]=="WW") ans.resize(3),ans[2]=1;
		if (s[l]=="BB") ans.resize(1),ans[0]=1;
		if (s[l]=="W?"||s[l]=="?W") ans.resize(3),ans[1]=1,ans[2]=1;
		if (s[l]=="B?"||s[l]=="?B") ans.resize(2),ans[0]=1,ans[1]=1;
		if (s[l]=="??") ans.resize(3),ans[0]=1,ans[1]=2,ans[2]=1;
		if (s[l]=="WB"||s[l]=="BW") ans.resize(2),ans[1]=1;
		return ans;
	}
	int mid=(l+r)>>1;
	return solve(l,mid)*solve(mid+1,r);
}
signed main()
{
	prework();
	n=read();
	for (int i=1;i<=n;i++) cin>>s[i];
	poly ans=solve(1,n);
	int cnt=0,all=1;
	if (len(ans)>=n+1) cnt=ans[n];
	for (int i=1;i<=n;i++)
	{
		if (s[i]=="WW"||s[i]=="BB")
		{
			all=0;
			break;
		}
		if (s[i]=="??") mul(all,2);
	}
	del(cnt,all);
	bool bl=1;
	for (int i=1;i<=n;i++) bl&=(s[i][0]!='W'&&s[i][1]!='B');
	if (bl) add(cnt,1);
	bl=1;
	for (int i=1;i<=n;i++) bl&=(s[i][0]!='B'&&s[i][1]!='W');
	if (bl) add(cnt,1);
	printf("%lld\n",cnt);
}