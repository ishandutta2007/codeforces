#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 600020

int main()
{
    int k,c[30],n,t;
	scanf("%d",&k); 
	n=0;
	if (k==0) {printf("abc\n");return 0;}
	while (k>0)
	{
		t=2;
		while ((t+1)*t/2<=k) t++;
		k-=(t-1)*t/2;
		c[++n]=t;
	}
	for (int i=1;i<=n;i++)
	    for (int j=0;j<c[i];j++)
	        printf("%c",96+i);
    printf("\n");
    return 0;
}