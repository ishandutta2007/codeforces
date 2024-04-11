#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	double t = sin(acos(-1)/(double)n);
	t = 1/t;
	t = t - 1;
	printf("%.9lf",(double)r/t);
	return 0;
}