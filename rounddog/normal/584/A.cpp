#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int n,t;

int main()
{
	scanf("%d%d",&n,&t);
	if (t==10)
	{
		if (n==1) printf("-1\n"); 
		else {
			printf("1");
			for (int i=2;i<=n;i++) printf("0");
			printf("\n");
		}
	}
	else {
	    for (int i=1;i<=n;i++) printf("%d",t);
	    printf("\n");
	}
	return 0;
}