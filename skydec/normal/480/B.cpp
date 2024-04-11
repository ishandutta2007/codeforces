#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
map<int,int>f;
int n,l,x,y;
int a[MAXN];
int main()
{
	scanf("%d%d%d%d",&n,&l,&x,&y);
	rep(i,1,n){scanf("%d",&a[i]);f[a[i]]=1;}
	bool f1,f2;f1=f2=0;
	rep(i,1,n){
		if(f[a[i]-x])f1=1;
		if(f[a[i]-y])f2=1;
	}
	if(f1&&f2){
		printf("0");
		return 0;
	}
	if(f1){
		printf("1\n%d\n",y);
		return 0;
	}
	if(f2){
		printf("1\n%d\n",x);
		return 0;
	}
	rep(i,1,n)
	if(f[a[i]-x-y]){
		printf("1\n%d",a[i]-y);
		return 0;
	}
	rep(i,1,n)
	if(f[a[i]-(y-x)]&&a[i]+x<=l){
		printf("1\n%d",a[i]+x);
		return 0;
	}
	rep(i,1,n)
	if(f[a[i]+(y-x)]&&a[i]-x>=0){
		printf("1\n%d",a[i]-x);
		return 0;
	}
	printf("2\n%d %d\n",x,y);
	return 0;
}