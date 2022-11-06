#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
		printf("%f\n",sqrt((double)i/n)*m);
	return 0;
}