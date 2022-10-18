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
const int N=3*1e5+100;
int T,n,a[N],rmn[N],lmn[N],rmx[N],lmx[N],dp[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit//
{
	int n;
	vector <int> sh;
	inline void init(int m){n=m;sh.resize(n+1);fill(sh.begin(),sh.end(),inf);}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x)ckmin(sh[x],v),x-=lowbit(x);}
	int query(int x){int ans=inf;while(x<=n)ckmin(ans,sh[x]),x+=lowbit(x);return ans;}
};
struct seg
{
	vector <int> sh[N*4];
	bit T[N*4];
	void build(int x,int l,int r,int v[])
	{
		sh[x].clear();
		for (int i=l;i<=r;i++) sh[x].emplace_back(v[i]);
		sort(sh[x].begin(),sh[x].end());
		T[x].init(len(sh[x]));
		if (l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid,v);build(rs,mid+1,r,v);
	}
	void change(int x,int l,int r,int wh,int val,int v[])
	{
		int pos=lower_bound(sh[x].begin(),sh[x].end(),v[wh])-sh[x].begin()+1;
		T[x].change(pos,val);
		if (l==r) return;
		int mid=(l+r)>>1;
		if (wh<=mid) change(ls,l,mid,wh,val,v);
		else change(rs,mid+1,r,wh,val,v);
	}
	int query(int x,int l,int r,int ll,int rr,int v)
	{
		if (ll<=l&&rr>=r)
		{
			int pos=lower_bound(sh[x].begin(),sh[x].end(),v)-sh[x].begin()+1;
			return T[x].query(pos);
		}
		int mid=(l+r)>>1,ans=inf;
		if (ll<=mid) ckmin(ans,query(ls,l,mid,ll,rr,v));
		if (rr>mid) ckmin(ans,query(rs,mid+1,r,ll,rr,v));
		return ans;
	}
}A;
seg B;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		if (n==1)
		{
			printf("0\n");
			continue;
		}
		stack <int> st;
		for (int i=1;i<=n;i++)
		{
			while (!st.empty()&&a[i]>a[st.top()]) rmx[st.top()]=i-1,st.pop();
			st.push(i);
		}
		while (!st.empty()) rmx[st.top()]=n,st.pop();
		for (int i=n;i>=1;i--)
		{
			while (!st.empty()&&a[i]>a[st.top()]) lmx[st.top()]=i+1,st.pop();
			st.push(i);
		}
		while (!st.empty()) lmx[st.top()]=1,st.pop();

		for (int i=1;i<=n;i++)
		{
			while (!st.empty()&&a[i]<a[st.top()]) rmn[st.top()]=i-1,st.pop();
			st.push(i);
		}
		while (!st.empty()) rmn[st.top()]=n,st.pop();
		for (int i=n;i>=1;i--)
		{
			while (!st.empty()&&a[i]<a[st.top()]) lmn[st.top()]=i+1,st.pop();
			st.push(i);
		}
		while (!st.empty()) lmn[st.top()]=1,st.pop();

		A.build(1,1,n,rmx);
		B.build(1,1,n,rmn);
		dp[1]=0;
		A.change(1,1,n,1,dp[1],rmx);
		B.change(1,1,n,1,dp[1],rmn);
		for (int i=2;i<=n;i++)
		{
			dp[i]=min(A.query(1,1,n,lmn[i],i-1,i),B.query(1,1,n,lmx[i],i-1,i))+1;
			A.change(1,1,n,i,dp[i],rmx);
			B.change(1,1,n,i,dp[i],rmn);
		}
		printf("%d\n",dp[n]);
	}
}