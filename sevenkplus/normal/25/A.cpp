#include<cstdio>
int a[111],n,f,g;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",a+i),(a[i]&1)?g++:f++;
	if(g==1){for(int i=1;i<=n;i++)if(a[i]&1)printf("%d\n",i);}
	else{for(int i=1;i<=n;i++)if(~a[i]&1)printf("%d\n",i);}
	return 0;
}