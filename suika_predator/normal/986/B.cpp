#include<cstdio>
int main()
{
	int n,x,cnt=0;
	scanf("%d",&n);
	if(n<=5)return printf("Petr\n"),0;
	for(int i=1;i<=n;i++)
		scanf("%d",&x),cnt+=(i==x);
	if(cnt<=2)printf("Um_nik\n");
	else printf("Petr\n");
	return 0;
}