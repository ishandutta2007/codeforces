#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int n;
string a;

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
	cin>>a;
	n=a.size();
	}

void solve()
	{
	int br=0;
	int i;
	for(i=0;i<n;i++)
		{
		if(a[i]>='A' && a[i]<='Z')br++;
		}
	if((br==n-1 && (a[0]>='a' && a[0]<='z')) || br==n)
		{
		for(i=0;i<n;i++)
			{
			if(a[i]>='A' && a[i]<='Z')
				{
				a[i]=a[i]-'A'+'a';
				}
			else
				{
				a[i]=a[i]-'a'+'A';
				}
			}
		}
	cout<<a<<"\n";
	}