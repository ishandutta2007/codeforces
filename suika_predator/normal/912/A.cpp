#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int a,b,x,y,z;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&x,&y,&z);
	long long aa=0ll+x+x+y,bb=0ll+z+z+z+y;
	printf("%lld\n",max(aa-a,0ll)+max(bb-b,0ll));
	return 0;
}