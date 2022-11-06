#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (((a-1)/c)*b>d) printf("YES\n"); else printf("NO\n");
	return 0;
}