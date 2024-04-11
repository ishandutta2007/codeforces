#include<stdio.h>
#include<iostream>
using namespace std;
int n,t,k,d;
int main(){
	cin>>n>>t>>k>>d;
	int a=(n+k-1)/k*t;
	if(a>d+t) printf("YES\n");
	else printf("NO\n");
	return 0;
}