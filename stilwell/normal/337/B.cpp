#include <stdio.h>
#include <stdlib.h>
using namespace std;

int a,b,c,d,A,B,g;

int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b*c<=a*d)A=(a*d-b*c)*c,B=a*c*d;
	else A=(b*c-a*d)*d,B=b*c*d;
	if(!A){printf("0/1\n");return 0;}
	g=gcd(A,B);
	printf("%d/%d\n",A/g,B/g);
}