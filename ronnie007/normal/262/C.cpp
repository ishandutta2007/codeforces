#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int m;
int n;
int a[100007];

int mn=1000000;

void input();
void solve();




int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
	scanf("%d",&m);
	int i;
	int x;
	for(i=0;i<m;i++)
		{
		scanf("%d",&x);
		if(x<mn)mn=x;
		}
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
    }


void solve()
    {
	sort(a,a+n);
	long long sm=0;
	int i=n-1;
	int j;
	while(i>=0)
		{
		for(j=0;j<mn;j++)
			{
			if(i>=j)
				{
				sm+=a[i-j];
				}
			else break;
			}
		i-=j;
		if(i>=0)i--;
		if(i>=0)i--;
		//printf("%d\n",i);
		}
	cout<<sm<<"\n";
    }