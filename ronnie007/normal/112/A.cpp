#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


char a[150],b[150];


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
	scanf("%s\n%s",&a,&b);
	}

void solve()
	{
	int i;
	int n=strlen(a);
	for(i=0;i<n;i++)
		{
		if(a[i]>='A' && a[i]<='Z')
			{
			a[i]=a[i]-'A'+'a';
			}
		}
	n=strlen(b);
	for(i=0;i<n;i++)
		{
		if(b[i]>='A' && b[i]<='Z')
			{
			b[i]=b[i]-'A'+'a';
			}
		}
	cout<<strcmp(a,b)<<"\n";
	}