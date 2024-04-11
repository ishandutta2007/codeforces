#include<cstdio>
using namespace std;

int Ans,x,now,n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if (x==-1)
			if (now>0) now--;else Ans++;
		else now+=x;
	}
	printf("%d\n",Ans);
	return 0;
}