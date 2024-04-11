#include <cstdio>
#include <algorithm>
using namespace std;
const int N=3e5+5;
const int M=2e6+5;
int n;
int p[N],idx[N];
int x[M],y[M],cnt;
void append(int a,int b)
{
	cnt++;
	x[cnt]=a;
	y[cnt]=b;
	swap(p[a],p[b]);
	swap(idx[p[a]],idx[p[b]]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		idx[p[i]]=i;
	}
	for (int i=2;i<n;i++)
	{
		bool cur=idx[i]<=n/2;
		bool dest=i<=n/2;
		append(idx[i],cur?n:1);
		cur^=1;
		if (cur^dest)
			append(idx[i],i);
		else
		{
			append(idx[i],cur?n:1);
			append(idx[i],i);
		}
	}
	if (idx[1]!=1)
		append(idx[1],1);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}