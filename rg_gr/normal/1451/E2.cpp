#include <stdio.h>
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
int query(int i,int j,const char* f)
{
	printf("%s %d %d\n",f,i,j);
	fflush(stdout);
	return read();
}
int a[100005],b[100005];
int main()
{
	/*while(1)
	{
		int a=read(),b=read();
		printf("%d %d %d\n",a^b,a&b,a|b);
	}*/
	// a+b = a^b + 2(a&b)
	int n=read(),a1,f=0;
	for(int i=2;i<=n;i++)a[i]=query(1,i,"XOR"),b[a[i]]++,b[a[i]]>1?f=a[i]:f=f;
	if(f||b[0])
	{
		if(f)
		{
			int c,d;
			for(int i=2;i<=n;i++)if(a[i]==f){c=i;break;}
			for(int i=c+1;i<=n;i++)if(a[i]==f){d=i;break;}
			int x=query(c,d,"AND");
			a1=a[c]^x;
			goto hi;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]==0)
			{
				a1=query(1,i,"AND");
				goto hi;
			}
		}
	}
	else
	{
		int aa,b;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1)
			{
				aa=query(1,i,"AND");
				break;
			}
		}
		for(int i=2;i<=n;i++)
		{
			if((a[i]&1)==0)
			{
				b=query(1,i,"AND")&1;
				break;
			}
		}
		a1=aa+b;
	}
	hi:;
	puts("!");
	printf("%d ",a1);
	for(int i=2;i<=n;i++)printf("%d ",a1^a[i]);
	
	fflush(stdout);
}