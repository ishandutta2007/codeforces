#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int N=1008;
char a[N];
int n,m;
int main(void)
{
	int i,j,k;
	scanf("%d%d%s",&n,&m,a+1);a[0]=0;
	if(n==1){if(++a[1]<='a'+m-1)printf("%s",a+1);else printf("NO");return 0;}
	for(i=n;i>=1;i--)if(a[i]<'a'+m-1){a[i]++;for(j=i+1;j<=n;j++)a[j]='a';break;}
	if(i<1){printf("NO");return 0;}
	i=2;
	while(i>=1&&i<=n)
	{
		k=0;
		while(a[i]<='a'+m-1&&((a[i]==a[i-1])||(i>=2&&a[i]==a[i-2]))){k=1;a[i]++;}
		if(a[i]<='a'+m-1){if(k){for(j=i+1;j<=n;j++){a[j]='a';}}i++;continue;}
		while(--i>=1&&a[i]=='a'+m-1);
		if(i<1)break;
		a[i]++;for(j=i+1;j<=n;j++)a[j]='a';
	}
	if(i<1){printf("NO");return 0;}
	printf("%s",a+1);
	return 0;
}