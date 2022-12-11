#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=(50+19)*1e4+19;
int x,Ans,cnt,sum,now,cur,n,d;
int A[Maxn],F[Maxn];

int main()
{
	scanf("%d%d",&n,&d);
	F[0]=1;
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&x);sum+=x;
		for (int j=sum;j>=x;j--) F[j]|=F[j-x];
	}
	for (int i=1;i<=sum;i++) if (F[i]) A[cnt++]=i;
	A[cnt]=(1<<30)-1;
	while (1)
	{
		int Flag=0;
		while (now+d>=A[cur]) cur++,Flag=1;
		if (!Flag) break;
		Ans++;now=A[cur-1];
	}
	printf("%d %d\n",now,Ans);
}