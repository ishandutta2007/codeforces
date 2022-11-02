#include <iostream>
#include <vector>
#define int long long
using namespace std;
int a[150005],b[150005],c[150005],d[150005],dp[150005];
struct stree
{
	int l,r,add,sum;
}t[550005];
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		t[now].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now].sum=min(t[now*2].sum,t[now*2+1].sum);
}
inline void give(int now,int d)
{
	t[now].add+=d,t[now].sum+=d;
}
inline void pushdown(int now)
{
	if(t[now].l!=t[now].r)
		give(now*2,t[now].add),give(now*2+1,t[now].add),t[now].add=0;
}
inline void change(int now,int l,int r,int d)
{
	if(t[now].l==l&&t[now].r==r)
	{
		give(now,d);
		return ;
	}
	pushdown(now);
	if(t[now*2].r>=r) change(now*2,l,r,d);
	else if(t[now*2+1].l<=l) change(now*2+1,l,r,d);
	else change(now*2,l,t[now*2].r,d),change(now*2+1,t[now*2+1].l,r,d);
	t[now].sum=min(t[now*2].sum,t[now*2+1].sum);
}
inline int query(int now,int l,int r)
{
	pushdown(now);
	if(t[now].l==l&&t[now].r==r) return t[now].sum;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	else return min(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
vector <int> e[150005];
const int inf=1e9;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1,n2,n3,n4,m1,m2,m3;
	cin >> n1 >> n2 >> n3 >> n4;
	for(int i=1;i<=n1;i++) cin >> a[i];
	for(int i=1;i<=n2;i++) cin >> b[i];
	for(int i=1;i<=n3;i++) cin >> c[i];
	for(int i=1;i<=n4;i++) cin >> d[i];
	build(1,1,max(n1,max(n2,max(n3,n4))));
	for(int i=1;i<=n2;i++) e[i].clear();
	cin >> m1;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin >> x >> y;
		e[y].push_back(x);
	}
	for(int i=1;i<=n2;i++)
	{
		vector <int> V;
		for(auto t:e[i])
			V.push_back(t),change(1,t,t,inf);
		dp[i]=query(1,1,n1)+b[i];
		for(auto t:V) change(1,t,t,-inf);
	}
	for(int i=1;i<=n2;i++) change(1,i,i,dp[i]-query(1,i,i));
	for(int i=1;i<=n3;i++) e[i].clear();
	cin >> m2;
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin >> x >> y;
		e[y].push_back(x);
	}
	for(int i=1;i<=n3;i++)
	{
		vector <int> V;
		for(auto t:e[i])
			V.push_back(t),change(1,t,t,inf);
		dp[i]=query(1,1,n2)+c[i];
		for(auto t:V) change(1,t,t,-inf);
	}
	for(int i=1;i<=n3;i++) change(1,i,i,dp[i]-query(1,i,i));
	for(int i=1;i<=n4;i++) e[i].clear();
	cin >> m3;
	for(int i=1;i<=m3;i++)
	{
		int x,y;
		cin >> x >> y;
		e[y].push_back(x);
	}
	for(int i=1;i<=n4;i++)
	{
		vector <int> V;
		for(auto t:e[i])
			V.push_back(t),change(1,t,t,inf);
		dp[i]=query(1,1,n3)+d[i];
		for(auto t:V) change(1,t,t,-inf);
	}
	int ans=inf;
	for(int i=1;i<=n4;i++) ans=min(ans,dp[i]);
	if(ans>5e8) ans=-1;
	cout << ans;
	return 0;
}