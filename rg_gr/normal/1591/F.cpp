#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=998244353;
const int M=5e5+10;
int n,a[M],pp[M],p[M];
map<int,int>t;
struct segment_tree
{
	struct tree
	{
		int tl,tr,val,len,tag1,tag2;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define len(x) t[(x)].len
	#define tag1(x) t[(x)].tag1
	#define tag2(x) t[(x)].tag2
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=(val(lson)+val(rson))%Mod;}
	void upd(int k,int a,int b)
	{
		val(k)=(val(k)*a+b*len(k))%Mod;
		tag1(k)=tag1(k)*a%Mod,tag2(k)=(tag2(k)*a+b)%Mod;
	}
	void pushdown(int k)
	{
		upd(lson,tag1(k),tag2(k)),upd(rson,tag1(k),tag2(k));
		tag1(k)=1,tag2(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag1(k)=1;
		if (l==r){len(k)=p[l]-p[l-1];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		len(k)=len(lson)+len(rson);
	}
	void update(int k,int l,int r,int a,int b)
	{
		if (l(k)>=l&&r(k)<=r){upd(k,a,b);return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,a,b),update(rson,l,r,a,b);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		pushdown(k);
		return (query(lson,l,r)+query(rson,l,r))%Mod;
	}
}T;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=pp[i]=read();
	sort(pp+1,pp+1+n);int cnt=0;
	for (int i=1;i<=n;i++)
		if (pp[i]!=pp[i-1])p[++cnt]=pp[i],t[pp[i]]=cnt;
	for (int i=1;i<=n;i++)a[i]=t[a[i]];
	T.build(1,1,cnt);T.update(1,1,a[1],1,1);
//	cout<<T.query(1,1,cnt)<<' ';
	for (int i=2;i<=n;i++)
	{
		int sum=T.query(1,1,cnt);
		T.update(1,a[i]+1,cnt,0,0);
		T.update(1,1,a[i],Mod-1,sum);
//		cout<<T.query(1,1,cnt)<<' ';
	}
	int ans=T.query(1,1,cnt);
	cout<<ans<<endl;
	return 0;
}