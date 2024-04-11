#include<cstdio>
using namespace std;

char c[20];
int t,tot,A[20];

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",c);
		tot=0;
		for (int a=1;a<=12;a++)
		{
			int b=12/a;
			if (b*a^12) continue;
			for (int i=0;i<b;i++)
			{
				int Flag=1;
				for (int j=0;j<a;j++) if (c[j*b+i]^'X') {Flag=0;break;}
				if (Flag) {A[tot++]=a;break;}
			}
		}
		printf("%d ",tot);
		for (int i=0;i<tot;i++) printf("%dx%d ",A[i],12/A[i]);
		printf("\n");
	}
}