#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,x,y,a,b; 

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b))
			puts("-1");
		else
			printf("%d\n",(y-x)/(a+b));
	}
}