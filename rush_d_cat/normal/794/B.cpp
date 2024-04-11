#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
int main(void)
{
	double m;
	int n,i;
	scanf("%d%lf",&n,&m);
	for(i=1;i<n;i++)
	{
		printf("%.12f ",m*sqrt(1.0*i/n));
	}
	return 0;
}