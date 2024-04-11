#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int flag = 0;
	if(c>=b-1 && c<=2*b+2) flag = 1;
	if(d>=a-1 && d<=2*a+2) flag = 1;
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
 }