#include<cstdio>
#include<iostream>
#include<cstring>
#define N 100005
using namespace std;
int n,k,m,a[N],tms[N],now,qwq;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;i++)
	scanf("%d",a+i),tms[a[i]%m]++;
	for(now=0;now<m;now++)
	if(tms[now]>=k)break;
	if(now==m){
		puts("No");return 0;
	}
	puts("Yes");
	for(int i=0;i<n&&qwq<k;i++)
	if(a[i]%m==now)printf("%d ",a[i]),qwq++;
}