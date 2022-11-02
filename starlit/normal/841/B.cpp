#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000005
using namespace std;
int n,a;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a&1)
		{puts("First");return 0;}
	}
	puts("Second");
}