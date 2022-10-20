#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int n;
string a[150];

void input();
void solve();
void put(int go,int goal,int num);


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
	for(i=0;i<n;i++)
		{
		cin>>a[i];
		if(a[i].size()<=10)cout<<a[i];
		else
			{
			cout<<a[i][0]<<a[i].size()-2<<a[i][a[i].size()-1];
			}
		cout<<"\n";
		}
	}

void solve()
	{
	}