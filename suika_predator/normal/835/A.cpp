#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a,b,c,d,e;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int t1=a*b+2*d,t2=a*c+2*e;
	if(t1<t2)printf("First\n");
	else if(t1>t2)printf("Second\n");
	else printf("Friendship\n");
	return 0;
}