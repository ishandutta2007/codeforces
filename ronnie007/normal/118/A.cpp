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
	int i;
	for(i=0;i<n;i++)
		{
		if(a[i]=='A' || a[i]=='O' || a[i]=='E' || a[i]=='Y' || a[i]=='U' || a[i]=='I' || a[i]=='a' || a[i]=='o' || a[i]=='e' || a[i]=='y' || a[i]=='u' || a[i]=='i')
			{
			a[i]=';';
			}
		}
	for(i=0;i<n;i++)
		{
		if(a[i]!=';')
			{
			if(a[i]>='A' && a[i]<='Z')
				{
				a[i]=a[i]-'A'+'a';
				}
			cout<<"."<<a[i];
			}
		}
	printf("\n");
	}