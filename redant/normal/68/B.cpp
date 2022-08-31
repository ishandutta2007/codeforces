#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a[10010];

int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	
	double lo = 0.0, hi = 1000.0;
	
	for(int t=0;t<100;t++)
	{
		double m = (lo+hi)/2.0;
		double more = 0.0, need = 0.0;
		for(int i=0;i<n;i++) if(a[i]>m) more+=a[i]-m; else need+=m-a[i];
		double can = more - more*k/100.0;
		if(can>=need) lo=m; else hi=m;
	}
	
	printf("%.10lf\n",(lo+hi)/2.0);		
	
	return 0;
}