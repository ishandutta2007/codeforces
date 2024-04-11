 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define p1 998244353
#define p2 342914237
#define base 5274747
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,id[N];
char s[N];
inline void add(int &a,int b,int mod){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b,int mod){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b,int mod){a=a*b%mod;}
inline int m_pow(int a,int b,int mod)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a,mod);
		b>>=1;
		mul(a,a,mod);
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
struct Hash
{
	int a,b;
}z[N];
Hash h[N],rh[N];
Hash operator +(Hash a,Hash b){add(a.a,b.a,p1);add(a.b,b.b,p2);return a;}
Hash operator -(Hash a,Hash b){del(a.a,b.a,p1);del(a.b,b.b,p2);return a;}
Hash operator *(Hash a,Hash b){mul(a.a,b.a,p1);mul(a.b,b.b,p2);return a;}
Hash operator *(Hash a,int b){mul(a.a,b,p1);mul(a.b,b,p2);return a;}
bool operator ==(Hash a,Hash b){return a.a==b.a&&a.b==b.b;}
Hash ask(int l,int r){return rh[l]-rh[r+1]*z[r-l+1];}
Hash Q(int id,int x)
{
	assert(x<=2*id);
	if (x>id) return h[id]*z[x-id]+ask(id-(x-id)+1,id);
	return h[x];
}
char find(int id,int x)
{
	if (x>id) return s[id-(x-id)+1];
	return s[x];
}
bool cmp(int a,int b)
{
	int l=min(a,b),r=2*min(a,b);
	while (l<r)
	{
		int mid=l+((r-l+1)>>1);
		if (Q(a,mid)==Q(b,mid)) l=mid;
		else r=mid-1;
	}
	if (l==2*min(a,b)) return a<b;
	return find(a,l+1)<find(b,l+1);
}
void prework()
{
	n=100000;
	z[0]=(Hash){1,1};
	for (int i=1;i<=n;i++) z[i]=z[i-1]*base;
}
signed main()
{
	prework();
	T=read();
	while (T--)
	{
		n=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
		{
			int x=s[i]-'a';
			h[i]=h[i-1]*base+(Hash){x,x};
		}
		for (int i=n;i>=1;i--)
		{
			int x=s[i]-'a';
			rh[i]=rh[i+1]*base+(Hash){x,x};
		}
		int x=1;
		for (int i=2;i<=n;i++) if (cmp(i,x)) x=i;
		for (int i=1;i<=x;i++) printf("%c",s[i]);
		for (int i=x;i>=1;i--) printf("%c",s[i]);
		printf("\n");
	}
}