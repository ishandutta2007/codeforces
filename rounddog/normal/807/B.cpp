#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 20000

using namespace std;

int x,y,p,z;
bool f;

int main()
{
	scanf("%d%d%d",&p,&x,&y);
	z=x;
	while (z-50>=y) z-=50;
	f=false;
	do{
		int t=(z/50)%475;
		for (int i=1;i<=25;i++)
		{
			t=(t*96+42)%475;
			if (t+26==p) f=true;
		}
		z+=50;
	}while (!f);
	if (z<x) z=x;
	printf("%d\n",(z-x)/100);
	return 0;
}