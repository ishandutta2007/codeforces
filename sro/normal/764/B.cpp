#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int Maxn=234567;

int n,a[Maxn],b[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<ceil(1.00*n/2);i++)
	{
		if((i%2)==0)
		{
			b[i]=a[n-i-1];
			b[n-i-1]=a[i];
		}
		else
		{
			b[i]=a[i];
			b[n-i-1]=a[n-i-1];
		}
	}
	for(int i=0;i<n;i++) printf("%d%c",b[i],(i==n-1)?'\n':' ');
	return 0;
}