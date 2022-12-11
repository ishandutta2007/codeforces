#include<cstdio>
using namespace std;

int n,m,Max,Min,tmp,Ans;
int Min_Flag=0,Max_Flag=0;

int main()
{
	scanf("%d%d%d%d",&n,&m,&Min,&Max);
	Ans=2;
	for (int i=0;i<m;i++)
	{
		scanf("%d",&tmp);
		if (tmp<Min||tmp>Max) {printf("Incorrect\n");return 0;}
		if (tmp==Min) Min_Flag=1;
		if (tmp==Max) Max_Flag=1; 
	}
	Ans-=Min_Flag+Max_Flag;
	if (n-m>=Ans) printf("Correct\n");else printf("Incorrect\n");
	return 0;
}