#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
using namespace std;
int n,k;
bool a[MAXN];
int fib[105];
int main()
{
	memset(fib,0,sizeof(fib));
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=20;i++)
		fib[i]=fib[i-1]+fib[i-2];
	memset(a,false,sizeof(a));
	for(int i=0;i<=20;i++)
		if(fib[i]<=1000) a[fib[i]]=true;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(a[i]) printf("O"); else printf("o");
	printf("\n");
	return 0;
}