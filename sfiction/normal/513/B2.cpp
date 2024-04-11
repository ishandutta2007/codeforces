#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int a[100];
	int n;
	long long m;
	scanf("%d",&n);
	cin>>m;
	--m;
	int l=1,r=n;
	long long t=1LL<<(n-2);
	for (int i=1;i<=n;++i,t>>=1)
		if (t&m)
			a[r--]=i;
		else
			a[l++]=i;
	printf("%d",a[1]);
	for (int i=2;i<=n;++i)
		printf(" %d",a[i]);
	return 0;
}