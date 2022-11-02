#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int n,a[N],b[N],qwq,mx,sec;
long long sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),sum+=a[i];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",b+i);
		if(b[i]>mx)sec=mx,mx=b[i];
		else if(b[i]>sec)sec=b[i];
	}
	puts(sum>mx+sec?"No":"Yes");
}