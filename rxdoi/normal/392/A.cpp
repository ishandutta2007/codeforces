#include<cstdio>
#include<cmath>
using namespace std;

int n,Ans;

int main()
{
	scanf("%d",&n);
	if (n==0) {printf("1\n");return 0;}
	for (int r=n-1;r;r--)
	{
		int x=sqrt(1.0*n*n-1.0*r*r);
		if (x>r) Ans+=2;
		if (x==r) Ans++;
	}
	printf("%d\n",(Ans+1)*4);
}