#include<bits/stdc++.h>
using namespace std;
int a , b , k;
int main()
{
	scanf("%d%d%d" , &a , &b , &k);
	if(a == 0 && b == 1 && k == 0)
	{
		printf("Yes\n1\n1");
		return 0;
	}
	if(a == 0 && b == 2 && k == 0)
	{
		printf("Yes\n11\n11");
		return 0;
	}
	if(a + b - 2 < k) 
	{
		printf("No");
		return 0;
	}
	if((!a || b <= 1) && k)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	if(!k)
	{
		for(int i = 1 ; i <= b ; i++ ) printf("1");
		for(int i = 1 ; i <= a ; i++ ) printf("0"); printf("\n");
		for(int i = 1 ; i <= b ; i++ ) printf("1");
		for(int i = 1 ; i <= a ; i++ ) printf("0"); printf("\n");
		return 0;
	}
	if(b - 1 >= k)
	{
		for(int i = 1 ; i <= b - k ; i++ ) printf("1");
		for(int i = 1 ; i < a ; i++ ) printf("0");
		for(int i = 1 ; i <= k ; i++ ) printf("1"); printf("0\n");
		for(int i = 1 ; i <= b - k ; i++ ) printf("1");
		for(int i = 1 ; i <= a ; i++ ) printf("0");
		for(int i = 1 ; i <= k ; i++ ) printf("1");
		return 0;
	}
	else
	{
		for(int i = 1 ; i < b ; i++ ) printf("1");
		for(int i = 1 ; i <= a + b - 2 - k ; i++ ) printf("0");
		printf("1");
		for(int i = 1 ; i <= k - b + 2 ; i++ ) printf("0");
		printf("\n");
		printf("10");
		for(int i = 1 ; i <= b - 2 ; i++ ) printf("1");
		for(int i = 1 ; i < a ; i++ ) printf("0");
		printf("1");
	}
	return 0;
}
/*
8 9 10
*/