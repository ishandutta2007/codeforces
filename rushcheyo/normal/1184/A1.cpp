#include<cstdio>
int main()
{
	long long r;
	scanf("%I64d",&r);
	if((r%2==0)||r<=3) {
		puts("NO");
	}
	else printf("1 %I64d",r-3>>1);
}