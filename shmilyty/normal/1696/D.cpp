#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,L,R,ans,top,stk[250001],a[250001],vis[250001],pos[250001],nxt1[250001],nxt2[250001],mx[250001][21],mn[250001][21],lg[250001];
void up()
{
	while(vis[L])
		L++;
	while(vis[R])
		R--;
}
int sm(int l,int r)
{
	int k=lg[r-l+1];
	if(a[mn[l][k]]<a[mn[r-(1<<k)+1][k]])
		return mn[l][k];
	return mn[r-(1<<k)+1][k];
}
int big(int l,int r)
{
	// cout<<l<<" "<<r<<endl;
	int k=lg[r-l+1];
	if(a[mx[l][k]]>a[mx[r-(1<<k)+1][k]])
		return mx[l][k];
	return mx[r-(1<<k)+1][k];

}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mx[i][0]=mn[i][0]=i;
		pos[a[i]]=i;
	}
	for(int i=1;i<=20;i++)
		for(int l=1;l+(1<<i)<=n+1;l++)
			if(a[mx[l][i-1]]<a[mx[l+(1<<(i-1))][i-1]])
				mx[l][i]=mx[l+(1<<(i-1))][i-1];
			else
				mx[l][i]=mx[l][i-1];
	for(int l=1;l<=20;l++)
		for(int i=1;i+(1<<l)<=n+1;i++)
			if(a[mn[i][l-1]]>a[mn[i+(1<<(l-1))][l-1]])
				mn[i][l]=mn[i+(1<<(l-1))][l-1];
			else
				mn[i][l]=mn[i][l-1];
	for(int i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
	top=0;
	stk[0]=n;
	for(int i=n;i;i--)
	{
		while(top&&a[stk[top]]<a[i])
			top--;
		nxt1[i]=stk[top];
		stk[++top]=i;
	}//
	top=0;
	for(int i=n;i;i--)
	{
		while(top&&a[stk[top]]>a[i])
			top--;
		nxt2[i]=stk[top];
		stk[++top]=i;
	}
	fill(vis+1,vis+1+n,0);
	L=1;
	R=n;
	ans=0;
	// cout<<nxt2[1]<<endl;
	// cout<<big(1,nxt2[1])<<endl;
	// system("pause");
	for(int i=1;i<n;ans++)
	{
		// cout<<L<<" "<<R<<" "<<i<<endl;
		vis[a[i]]=1;
		up();
		if(a[i+1]>a[i])
			i=big(i,nxt2[i]);
		else
			i=sm(i,nxt1[i]);
	}
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}