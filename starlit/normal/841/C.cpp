#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
using namespace std;
int n,a[N],b[N],no[N];
bool cmp(int x,int y)
{return b[x]>b[y];}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",a+i);
	for(int i=0;i<n;i++)
	scanf("%d",b+i),no[i]=i;
	sort(no,no+n,cmp);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	b[no[i]]=a[i];
	printf("%d",b[0]);
	for(int i=1;i<n;i++)
	printf(" %d",b[i]);
}