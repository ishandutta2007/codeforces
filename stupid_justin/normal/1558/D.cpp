#include<bits/stdc++.h>
#include<ext/rope>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
using namespace __gnu_cxx;
const int N=4e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,c,ans,d;
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=1ll*ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int sum=0,R=0;
struct Node{int son[2],rd,w,sz,tag;}T[N];
int idx,rt;

int insert(int w){idx++;T[idx].son[0]=T[idx].son[1]=T[idx].tag=0;T[idx].w=w;T[idx].sz=1;T[idx].rd=rand();return idx;}
void pushup(int x){if (!x) return;T[x].sz=T[T[x].son[0]].sz+T[T[x].son[1]].sz+1;}
void pushdown(int x){if (!x) return;if (T[x].tag){for (int i=0;i<=1;i++) if (T[x].son[i]) T[T[x].son[i]].w+=T[x].tag,T[T[x].son[i]].tag+=T[x].tag;T[x].tag=0;}}
void split(int p,int k,int &x,int &y)
{
	if (!p){x=y=0;return;}pushdown(p);
	if (k>=T[p].w){x=p;split(T[p].son[1],k,T[p].son[1],y);}
	else{y=p;split(T[p].son[0],k,x,T[p].son[0]);}
	pushup(p);
}
int merge(int x,int y)
{
    if (!x || !y) return x+y;
    if (T[x].rd<T[y].rd){pushdown(x);T[x].son[1]=merge(T[x].son[1],y);pushup(x);return x;}
    else {pushdown(y);T[y].son[0]=merge(x,T[y].son[0]);pushup(y);return y;}
}
bool find(int x,int p)
{
	if (!p) return 0;
	if (T[p].w==x) return 1;
	pushdown(p);
    if (x<T[p].w) return find(x,T[p].son[0]);else return find(x,T[p].son[1]);
}
void DOIT()
{
	rd(n);rd(m);
	rt=idx=0;
	for (int i=1;i<=m;i++)
	{
		int a,b,x,y;
		rd(a);rd(b);
		bool flag=find(b,rt);
		split(rt,b-1,x,y);
		if (y) T[y].w++,T[y].tag++;
		if (flag) rt=merge(x,y);else rt=merge(x,merge(insert(b+1),y));
	}
	ans=C(n+n-idx-1,n);
	cout<<ans<<"\n";

}
signed main()
{
	unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand(seed);
	Init(N-1);
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*
$a_4<a_3\le a_5<a_1 \le a_2$
*/