#include<cstdio>
using namespace std;

const int Maxn=4000+19;
int A[Maxn],B[Maxn],C[Maxn];
int n,opt,x,y,now,cnt,Ans;

int main()
{
	scanf("%d%d",&now,&n);
	for (int i=1;i<now;i++) B[i]=1;
	while (n--)
	{
		scanf("%d",&opt);
		scanf("%d",&x),B[x]=0;
		if (opt==1) scanf("%d",&y),B[y]=0;
	}
	for (int i=1;i<now;i++) if (B[i]==1) A[++cnt]=i;
	Ans=cnt;
	for (int i=2;i<=cnt;i++)
		if (A[i]-A[i-1]==1&&!C[i-1]) C[i]=C[i-1]=1,Ans--;
	printf("%d %d\n",Ans,cnt);
}