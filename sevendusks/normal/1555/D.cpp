/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,m,p[4];
char s[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct tree
{
	int sum[3][N*4];
	char t[3];
	inline void pushup(int x)
	{
		for (int i=0;i<3;i++) sum[i][x]=sum[i][ls]+sum[i][rs]; 
	}
	void build(int x,int l,int r)
	{
		if (l==r)
		{
			for (int i=0;i<3;i++) sum[i][x]=(s[l]!=t[(l-1+i)%3]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	int query(int x,int l,int r,int ll,int rr,int op)
	{
		if (ll<=l&&rr>=r) return sum[op][x];
		int mid=(l+r)>>1,ans=0;
		if (ll<=mid) ans+=query(ls,l,mid,ll,rr,op);
		if (rr>mid) ans+=query(rs,mid+1,r,ll,rr,op);
		return ans;
	}
}T[6];
signed main()
{
	n=read();m=read();
	scanf("%s",s+1);
	for (int i=1;i<=3;i++) p[i]=i;
	int cnt=0;
	do
	{
		for (int i=1;i<=3;i++)
		{
			T[cnt].t[i-1]='a'+p[i]-1;
		}
		cnt++;
	}while(next_permutation(p+1,p+4));
	for (int i=0;i<6;i++) T[i].build(1,1,n);
	while (m--)
	{
		int l=read(),r=read(),ans=inf;
		for (int i=0;i<6;i++)
		{
			ans=min(ans,T[i].query(1,1,n,l,r,0));
			ans=min(ans,T[i].query(1,1,n,l,r,1));
			ans=min(ans,T[i].query(1,1,n,l,r,2));
		}
		printf("%d\n",ans);
	}
}