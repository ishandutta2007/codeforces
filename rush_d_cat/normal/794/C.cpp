#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=300008;
char a[N],b[N],c[N];
int n;
int main(void)
{
	int i,k,left,right,a1,a2,b1,b2;
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	a1=1;a2=n/2+(n&1);
	b1=n-(n/2)+1;b2=n;
	left=1;right=n;k=1;
	while(k<=n)
	{
		if(k<=n)
		{
			if(a[a1]<b[b2])c[left++]=a[a1++];
			else c[right--]=a[a2--];
			k++;
		}
		if(k<=n)
		{
			if(b[b2]>a[a1])c[left++]=b[b2--];
			else c[right--]=b[b1++];
			k++;
		}
	}
	for(i=1;i<=n;i++)printf("%c",c[i]);
	return 0;
}