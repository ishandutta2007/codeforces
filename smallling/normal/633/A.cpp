#include<cstdio>

using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=100000;i++)
	{
		if(c-b*i<0)break;
		if((c-b*i)%a==0)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}