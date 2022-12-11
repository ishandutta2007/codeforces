#include<cstdio>

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if (k>(n*n+1)/2) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++) putchar(!k||(i&1^j&1)?'S':(k--,'L'));
}