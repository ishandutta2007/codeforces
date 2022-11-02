#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,v1,v2,t1,t2;
int main()
{
	scanf("%d%d%d%d%d",&n,&v1,&v2,&t1,&t2);
	v1=v1*n+t1*2;
	v2=v2*n+t2*2;
	if(v1<v2)puts("First");
	else if(v1>v2)puts("Second");
	else puts("Friendship");
}