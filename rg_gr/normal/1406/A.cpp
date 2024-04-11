#include <stdio.h>
#include <string.h>
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
int a[105];
int main()
{
	int t=read();
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n=read();
		while(n--)
		{
			int c=read();a[c]++;
		}
		int ans=0;
		for(int j=0;j<2;j++)
			for(int i=0;i<=101;i++)
			{
				if(a[i]>0)a[i]--;
				else 
				{
					ans+=i;
					break;
				}
			}
		printf("%d\n",ans);
	}
}