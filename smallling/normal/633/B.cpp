#include<cstdio>

using namespace std;

int m;

int main()
{
	scanf("%d",&m);
	for(int i=5;;i+=5)
	{
		int now=i,cnt=0;
		while(now%5==0)cnt++,now/=5;
		m-=cnt;
		if(m<0)
		{
			puts("0");
			return 0;
		}
		if(m==0)
		{
			puts("5");
			for(int j=i;j<i+5;j++)
				printf("%d ",j);
			return 0;
		}
	}
}