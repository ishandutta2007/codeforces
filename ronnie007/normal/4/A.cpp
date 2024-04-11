#include<iostream>
#include<stdio.h>
using namespace std;


int n;


void input();


int main()
	{
	input();
	//system("pause");
	return 0;
	}


void input()
	{
	scanf("%d",&n);
	if(n%2==0 && n!=2)printf("YES\n");
	else printf("NO\n");
	}