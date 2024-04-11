#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int N=1e6+5;
int n,q;
long long a[N];
int C[N];
long long v[N];
set <int> B;
void segadd(int u,long long x)
{
	for (int i=u;i<=n;i+=(i&(-i)))
		a[i]+=x;
}
long long segqry(int u)
{
	long long r=0;
	for (int i=u;i;i-=(i&(-i)))
		r+=a[i];
	return r;
}
void color(int l,int r,int c)
{
	if (l>1)
	{
		int lb=*B.lower_bound(l-1);
		if (lb!=l-1)
		{
			C[l-1]=C[lb];
			B.insert(l-1);
		}
	}
	int cl=l;
	while (cl<=r)
	{
		int lb=*B.lower_bound(cl);
		if (lb<=r)
		{
			segadd(cl,v[C[lb]]);
			segadd(lb+1,-v[C[lb]]);
			B.erase(lb);
		}
		else
		{
			segadd(cl,v[C[lb]]);
			segadd(r+1,-v[C[lb]]);
		}
		cl=lb+1;
	}
	C[r]=c;
	segadd(l,-v[c]);
	segadd(r+1,v[c]);
	B.insert(r);
}
void add(int c,int x)
{
	v[c]+=x;
}
void query(int x)
{
	int lb=*B.lower_bound(x);
	long long r=segqry(x)+v[C[lb]];
	printf("%lld\n",r);
}
int main()
{
	scanf("%d%d",&n,&q);
	B.insert(n);
	C[n]=1;
	char s[255];
	int l,r,c,x;
	while (q--)
	{
		scanf("%s",s+1);
		if (s[1]=='C')
		{
			scanf("%d%d%d",&l,&r,&c);
			color(l,r,c);
		}
		if (s[1]=='A')
		{
			scanf("%d%d",&c,&x);
			add(c,x);
		}
		if (s[1]=='Q')
		{
			scanf("%d",&x);
			query(x);
		}
	}
	return 0;
}