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
int a[100005];
int main()
{
	/*while(1)
	{
		int a=read(),b=read();
		printf("%d %d %d\n",a^b,a&b,a|b);
	}*/
	// a+b = a^b + 2(a&b)
	int n=read();
	for(int i=2;i<=n;i++)a[i]=query(1,i,"XOR");
	int a12=query(1,2,"AND")*2+a[2];
	int a13=query(1,3,"AND")*2+a[3];
	int a23=query(3,2,"AND")*2+(a[2]^a[3]);
	int a1=(a12+a13+a23)/2-a23;
	puts("!");
	printf("%d ",a1);
	for(int i=2;i<=n;i++)printf("%d ",a1^a[i]);
	fflush(stdout);
}