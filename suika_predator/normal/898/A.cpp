#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	if(n%10>=5)printf("%d\n",n/10*10+10);
	else printf("%d\n",n/10*10);
	return 0;
}