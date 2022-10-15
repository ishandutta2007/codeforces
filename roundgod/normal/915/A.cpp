#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,k;
int a[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int res=INF;
	for(int i=0;i<n;i++)
		if(k%a[i]==0) res=min(res,k/a[i]);
	printf("%d\n",res);
	return 0;
}