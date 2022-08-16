#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int a,b,g,c;
	scanf("%d %d",&a,&b);
	a=max(a,b);
	a=6-a+1;
	g=__gcd(a,6);
	printf("%d/%d",a/g,6/g);
	return 0;
}