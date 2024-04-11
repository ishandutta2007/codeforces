#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string a;
string b;
int n;
int t;

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
	scanf("%d%d\n",&n,&t);
	cin>>a;
	}
void solve()
	{
	int br=0;
	int i,j;
	for(i=1;i<=t;i++)
		{
		b=a[0];
		for(j=1;j<n;j++)
			{
			b+=a[j];
			if(a[j]=='G' && a[j-1]=='B')
				{
				swap(b[j],b[j-1]);
				}
			}
		a=b;
		}
	cout<<a<<"\n";
	}