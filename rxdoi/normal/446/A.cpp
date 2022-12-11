#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100000+19;
int A[Maxn],Le[Maxn],Ri[Maxn],cnt,L,R,n,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	Le[cnt=1]=1;A[++n]=A[n-1]-1;
	for (int i=1;i<=n;i++)
		if (A[i]<=A[i-1]) 
		{
			Ri[cnt]=i-1;Ans=max(Ans,Ri[cnt]-Le[cnt]+1);Le[++cnt]=i;
		}
	for (int i=1;i<cnt;i++)
	{
		if (Ri[i]<n-1||Le[i]>1) Ans=max(Ans,Ri[i]-Le[i]+2);
		if (i>1)
			if (Ri[i-1]>Le[i-1]&&Ri[i]>Le[i]) 
			{
				if (A[Ri[i-1]-1]<A[Le[i]]-1||A[Ri[i-1]]<A[Le[i]+1]-1) 
					Ans=max(Ans,Ri[i]-Le[i-1]+1);
			} else 
			{
				if (Ri[i-1]==Le[i-1]) Ans=max(Ans,Ri[i]-Le[i]+2);
				if (Ri[i]==Le[i]) Ans=max(Ans,Ri[i-1]-Le[i-1]+2);
			}
	}
	printf("%d\n",Ans);
}