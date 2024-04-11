#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


int n;
string a[10];



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
	a[1]="Sheldon";
	a[2]="Leonard";
	a[3]="Penny";
	a[4]="Rajesh";
	a[5]="Howard";
	}


void solve()
	{
	int i=5;
	int br=1;
	while(n>i)
		{
		n=n-i;
		//printf("%d\n",n);
		i=i*2;
		br=br*2;
		//printf("%d %d\n",br+1,n);
		}
	int x;
	//cout<<n<<"\n";
	x=n/br;
	if(n%br!=0)x++;
	cout<<a[x]<<"\n";
	}