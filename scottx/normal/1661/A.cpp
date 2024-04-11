#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,x[N],y[N];
long long v;
void sol()
{
	scanf("%d",&n);
	v=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&y[i]);
	for(int i=1;i<=n;i++)
	{
		if(x[i]>y[i])
			swap(x[i],y[i]);
		if(i!=1)
			v+=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
	}
	printf("%lld\n",v);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}