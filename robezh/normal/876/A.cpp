#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int dist = 0;
	if(n == 1) dist = 0;
	else{
		dist += min(a,b);
		dist += (n-2) * min(min(a,b),c);
	}
	printf("%d",dist);
}