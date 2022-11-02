#include<iostream>
#include<cstdio>
#include<algorithm> 
#define N 233
using namespace std;
int n,a[N],loc;
bool check(int x)
{
	for(int i=1;i<x;i++)
	if(abs(a[i]-a[i+1])>1)return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=n;i;i--)
	{
		if(check(i))return puts("NO"),0;
		loc=0;
		for(int j=1;j<=i;j++)
		if(a[j]>a[loc])loc=j;
		for(int j=loc;j<i;j++)a[j]=a[j+1];
	}
	puts("YES");
}