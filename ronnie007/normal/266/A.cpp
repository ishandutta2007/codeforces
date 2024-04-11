#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string a;
int n;

void input();
void solve();



int main()
	{
	input();
	solve();
	return 0;
	}


void input()
	{
	scanf("%d\n",&n);
	cin>>a;
	}
void solve()
	{
	int br=0;
	for(int i=1;i<n;i++)
		{
		if(a[i]==a[i-1])br++;
		}
	cout<<br<<"\n";
	}