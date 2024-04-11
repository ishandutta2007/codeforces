#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i<<=1)
	n-=i,s++;
	if(n)s++;
	printf("%d",s);
}