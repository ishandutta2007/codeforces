#include<iostream>
#include<stdio.h>
using namespace std;

int n;
long long a[100007];
long long b[100007];

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
		scanf("%I64d",&a[i]);
		}
	}

void solve()
	{
	int i;
	long long last=0;
	long long br=0;
	for(i=1;i<n;i++)
		{
		if(a[i]+last<a[i-1])
	      	{
          	//cout<<k<<endl;
          	br+=a[i-1]-(a[i]+last);
          	last+=a[i-1]-(a[i]+last);
          	a[i]=a[i-1];
			}
      	else
      		{
          	if(a[i]<a[i-1]){last=a[i-1]-a[i];a[i]=a[i-1];}
			else last=0;
      		}

		}
	printf("%I64d\n",br);
	}