#include<iostream>
#include<stdio.h>
using namespace std;



long long a[100008];
long long n;
long long last;

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
	cin>>n>>last;
	int i;
	for(i=1;i<=n;i++)
		{
		cin>>a[i];
		}
	}
void solve()
	{
	long long i;
	long long br=0;
	long long mn=1000000009;
	long long ind;
	if(last!=n)
		{
		for(i=last;i>=1;i--)
			{
			br++;a[i]--;
			}
		}
	last=n;
	for(i=last;i>=1;i--)
		{
		if(mn>a[i])
			{
			mn=a[i];
			ind=i;
			}
		}
	for(i=1;i<=n;i++)
		{
		br+=mn;
		a[i]=a[i]-mn;
		}
	for(i=n;i>ind;i--)
		{
		a[i]--;
		br++;
		}
	a[ind]=br;
	for(i=1;i<=n;i++)
		{
		cout<<a[i]<<" ";
		}
	}