#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
int a,b,m;
int main(void)
{
	int k;
	cin>>a>>m;b=0;
	k=0;
	while(a||b>=m)
	{
		if(a){k+=a;b+=a;a=0;}
		else{k+=b/m;b=b-b/m*m+b/m;}
	}
	cout<<k;
	return 0;
}