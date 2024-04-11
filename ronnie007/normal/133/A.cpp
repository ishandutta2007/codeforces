#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main()
	{
	string a;
	cin>>a;
	int i;
	int n=a.size();
	for(i=0;i<n;i++)
		{
		if(a[i]=='H' || a[i]=='Q' || a[i]=='9')
			{
			printf("YES\n");
			return 0;
			}
		}
	printf("NO\n");
	//system("pause");
	return 0;
	}