#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


long long n;

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
	scanf("%I64d",&n);
    }

void solve()
	{
	long long i;
	long long ans=0;
	for(i=1;i<n;i++)
		{
		ans=ans+i*(n-i)+1;
		}
	printf("%I64d\n",ans+1);
	}