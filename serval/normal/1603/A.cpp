#include <cstdio>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N];
int l[N],r[N];
bool solve()
{
	scanf("%d",&n);
	r[0]=1;
	l[n+1]=n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=i-1;
		r[i]=i+1;
	}
	for (int i=1;i<=n;i++)
	{
		int p=n+1,c=n-i+1;
		p=l[p];
		while (p&&a[p]%(c+1)==0)
			p=l[p],c--;
		if (p==0)
			return 0;
		r[l[p]]=r[p];
		l[r[p]]=l[p];
	}
	return 1;
}
int main()
{
	scanf("%d",&t);
	while (t--)
		printf(solve()?"YES\n":"NO\n");
	return 0;
}