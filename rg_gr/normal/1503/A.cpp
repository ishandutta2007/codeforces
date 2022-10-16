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
	while(c<48||c>49){c=getchar();}
	return c&1;
}
int a[200005];
int b[200005],c[200005];
signed main()
{
    int T=read();
    while(T--)
    {
    	int n=read(),sum1=1,sum2=1;
		for(int i=0;i<n;i++)a[i]=re1d()^1;
		if(a[0]==1)
		{
			puts("NO");
			goto ng;
		}
		b[0]=c[0]=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]==0)b[i]=c[i]=1,sum1++,sum2++;
			else if(sum1>sum2)sum1--,sum2++,b[i]=0,c[i]=1;
			else sum1++,sum2--,b[i]=1,c[i]=0;
			if(sum1<0||sum2<0){puts("NO");goto ng;}
		}
		if(sum1!=sum2){puts("NO");goto ng;}
		for(int i=n-1;i>=0;i--)
		{
			if(sum1==0)break;
			if(b[i]==1&&c[i]==1)sum1-=2,b[i]=0,c[i]=0;
		}
		sum1=sum2=0;
		for(int i=0;i<n;i++)
		{
			if(b[i])sum1++;else sum1--;
			if(c[i])sum2++;else sum2--;
			if(sum1<0||sum2<0){puts("NO");goto ng;}
		}
		puts("YES");
		for(int i=0;i<n;i++)if(b[i])putchar('(');else putchar(')');puts("");
		for(int i=0;i<n;i++)if(c[i])putchar('(');else putchar(')');puts("");
		/*for(int i=0;i<n;i++)
		{
			int q;
			if(i<(n>>1))q=1;
			else q=0;
			q^=a[i];
			if(q)sum++;
			else
			{
				if(sum==0)
				{
					puts("NO");
					goto ng;
				}
				sum--;
			}
		}
		if(sum){puts("NO");goto ng;}
		puts("YES");
		for(int i=0;i<n;i++)if(i<(n>>1))putchar('(');else putchar(')');puts("");
		for(int i=0;i<n;i++)
		{
			int q;
			if(i<(n>>1))q=1;
			else q=0;
			q^=a[i];
			if(q)putchar('(');
			else putchar(')');
		}
		puts("");*/
		ng:;
	}
    //printf("%.10lf\n",1.0*(n*n+n)/(4*n-2));
	return 0;
}