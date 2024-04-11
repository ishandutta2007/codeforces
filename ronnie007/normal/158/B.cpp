#include<iostream>
#include<stdio.h>
using namespace std;


int n;
int a[100007];
int b;
int c;
int d;
int br=0;



void input();
void solve();


int main()
	{
	input();
	solve();
	//system("pause");
	return 0;
	}


void input()
	{
	scanf("%d",&n);
	int i;
	b=0;
	c=0;
	d=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		if(a[i]==1)b++;
		if(a[i]==2)c++;
		if(a[i]==3)d++;
		if(a[i]==4)br++;
		}
	}


void solve()
	{
	br+=d;
	b-=d;
	if(b<0)b=0;
	c*=2;
	c+=b;
	br+=c/4;
	if(c%4!=0)br++;
	printf("%d\n",br);
	}