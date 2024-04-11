#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
int n,t,f,w,sum,Ans;
int A[Maxn],Q[Maxn];

int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&A[i]);
		sum+=A[i];
		Q[++f]=A[i];
		while (sum>t) sum-=Q[++w];
		Ans=max(Ans,f-w);
	}
	printf("%d\n",Ans);
}