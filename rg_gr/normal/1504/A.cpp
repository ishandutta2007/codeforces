#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<'a'||c>'z'){c=getchar();}
	return c-97;
}
//aabaa
char a[300005];
int b[300005];
signed main()
{
	//freopen("tjrksbfg.out","w",stdout);
    int T=read();
    while(T--)
    {
    	scanf("%s",a);
		int n=strlen(a);
		if(a[n-1]!='a')
		{
			puts("YES");
			putchar(97);
			printf("%s\n",a);
		}
		else
		{
			int f=0;
			for(int i=0,j=n-2;i<n-1;i++,j--)if(a[i]!=a[j])
			{
				f=1;break;
			}
			if(f)
			{
				puts("YES");
				putchar(97);
				printf("%s\n",a);
			}
			else
			{
				if(a[0]!='a')
				{
					puts("YES");
					printf("%sa\n",a);
				}
				else
				{
					int f=0;
					for(int i=1,j=n-1;i<n;i++,j--)if(a[i]!=a[j])
					{
						f=1;break;
					}
					if(f)printf("YES\n%sa\n",a);
					else puts("NO");
				}
			}
		}
		ng:;
	}
    return 0;
}