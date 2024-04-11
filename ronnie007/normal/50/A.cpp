#include<iostream>
#include<stdio.h>
using namespace std;


int n,m;
int x,y;
int mx=0;


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
	scanf("%d%d",&n,&m);
	}

void solve()
	{
	if(mx<n/2*m+n%2*m/2)
		{
		mx=n/2*m+n%2*m/2;
		}
	if(mx<m/2*n+m%2*n/2)
		{
		mx=m/2*n+m%2*n/2;
		}
	printf("%d\n",mx);
	}