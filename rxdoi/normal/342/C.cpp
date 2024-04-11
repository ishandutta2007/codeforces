#include<cmath>
#include<cstdio>
using namespace std;

typedef double D;
int r,h;

int main()
{
	scanf("%d%d",&r,&h);
	D x=D(h%r)/D(r);
	printf("%d\n",h/r*2+1+(x>=0.5)+(x>=sqrt(3.0)/2.));
}