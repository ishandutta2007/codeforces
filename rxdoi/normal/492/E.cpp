#include<cstdio>
using namespace std;

const int Maxn=1e6+19;
int n,m,dx,dy,x,y,t;
int A[Maxn],Ans[Maxn];

int main()
{
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	for (int i=0;i<n;i++) A[x]=y,(x+=dx)%=n,(y+=dy)%=n;
	while (m--)
	{
		scanf("%d%d",&x,&y);
		Ans[(y-A[x]+n)%n]++;
	}
	for (int i=0;i<n;i++) if (Ans[i]>Ans[t]) t=i;
	printf("0 %d\n",t);
}