#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int n;
int a[50];
int b[50];

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
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		{
		scanf("%d%d",&a[i],&b[i]);
		}
    }


void solve()
    {
	int i,j;
	int br=0;
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(a[i]==b[j]){br++;}
			}
		}
	printf("%d\n",br);
    }