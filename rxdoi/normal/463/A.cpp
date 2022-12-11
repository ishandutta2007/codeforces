#include<cstdio>
using namespace std;

int n,s,Ans,x,y;

int main()
{
	scanf("%d%d",&n,&s);
	Ans=-1;
	while (n--)
	{
		scanf("%d%d",&x,&y);
		if (y==0) x--,y=100;
		if (x>=s) continue;
		if (100-y>Ans) Ans=100-y;
	}
	printf("%d\n",Ans);
}