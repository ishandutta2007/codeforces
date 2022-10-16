#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,m;
int a[MAXN];
struct atom
{
	int x,y;
	int id;
	inline bool operator<(const atom &a)const{return y>a.y;}
}arr[MAXN];
inline bool cmp(const atom &a,const atom &b){return a.id<b.id;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i].y);
		arr[i].id=i;
	}
	sort(arr+1,arr+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		arr[i].x=a[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",arr[i].x);
	}
	return 0;
}