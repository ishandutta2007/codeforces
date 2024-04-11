#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=5e5+19;
int A[Maxn],vis[Maxn],n,Ans,now;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	now=n-1;
	for (int i=n/2-1;i>=0;i--)
	{
		while (vis[now]) now--;
		if (A[now]<A[i]*2) continue;
		vis[i]=vis[now]=1;Ans++;
	}
	printf("%d\n",n-Ans);
}