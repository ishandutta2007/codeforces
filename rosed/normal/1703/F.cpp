#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int N=5e5+10,inf=2e9;
int n,m;
int a[N],b[N],c[N],d[N];
int tr[N];
inline void update(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=k;
}
inline int query(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
	return sum;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			tr[i]=0;
			cin>>a[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i]>=i) continue;
			if(a[i]-1>0) ans+=query(a[i]-1);
			update(i,1);
		}
		cout<<ans<<'\n';

	}
	return 0;
}
/*
4 1 2 3 2 1
*/