#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(!n)return printf("a\n"),0;
	char ch='a';
	while(n)
	{
		int i;
		for(i=1;i*(i+1)<=n*2;i++);
		for(int j=1;j<=i;j++)printf("%c",ch);
		n-=i*(i-1)/2;
		ch++;
	}
	printf("\n");
	return 0;
}