#include <cstdio>
using namespace std;
int n;
int k;
char s[1005];
int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&k);
		scanf("%s",s+1);
		bool p=1;
		int c=0,r=0;
		for (int i=1;i<=(k+1)>>1;i++)
		{
			p&=(s[i]==s[k-i+1]);
			c+=(s[i]!=s[k-i+1]);
		}
		for (int i=1;i<=k;i++)
			r+=(s[i]=='0');
		if (p)
			if (r&1)
				if (r==1)
					printf("BOB\n");
				else
					printf("ALICE\n");
			else
				printf("BOB\n");
		else
		{
			bool o=k&1;
			if (o&&s[(k+1)>>1]=='1')
				o=0;
			if (c==1&&o)
				if (r==2)
					printf("DRAW\n");
				else
					printf("ALICE\n");
			else
				printf("ALICE\n");
		}
	}
	return 0;
}