#include <cstdio>
using namespace std;
int q,a;
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&a);
		if (__builtin_popcount(a+1)==1)
		{
			if (a%3==0)
				printf("%d\n",a/3);
			else
				if (a%7==0)
					printf("%d\n",a/7);
				else
					if (a%15==0)
						printf("%d\n",a/15);
					else
						if (a%23==0)
							printf("%d\n",a/23);
						else
							if (a%31==0)
								printf("%d\n",a/31);
							else
								if(a%47==0)
									printf("%d\n",a/47);
								else
									printf("1\n");
		}
		else
		{
			a=32-__builtin_clz(a);
			printf("%d\n",(1<<a)-1);
		}
	}
	return 0;
}