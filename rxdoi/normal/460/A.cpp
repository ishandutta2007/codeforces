#include<cstdio>
using namespace std;

int n,m,Ans,cnt;

int main()
{
	scanf("%d%d",&cnt,&m);
	for (Ans=1;cnt;Ans++)
	{
		cnt--;
		if (Ans%m==0) cnt++;
	}
	printf("%d\n",Ans-1);
}