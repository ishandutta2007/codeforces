#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=0;i<MAXN;i++)
		if(a[i]&1) {puts("Conan"); return 0;}
	puts("Agasa");
	return 0;
}