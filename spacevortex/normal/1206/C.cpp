#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n;
int a[N];
int main()
{
	int i;
	scanf("%d",&n);
	if(n%2==0) 
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(i&1) a[i]=i*2-1,a[i+n]=i*2;
		else a[i]=i*2,a[i+n]=i*2-1;
	}
	puts("YES");
	for(i=1;i<=n*2;i++) printf("%d ",a[i]);
	return 0;
}