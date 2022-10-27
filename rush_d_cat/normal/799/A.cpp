#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
int maxx(int x,int y){if(x>y)y=x;return y;}
int main(void)
{
	int n,t1,m,t2;
	cin>>n>>t1>>m>>t2;
	int p1=((n-1)/m+1)*t1;
	int p2=(p1-1)/t1*m+maxx(p1-1-t2,0)/t1*m;
	if(p2>=n)printf("YES");else printf("NO");
	return 0;
}