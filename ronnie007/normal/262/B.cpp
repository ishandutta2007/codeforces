#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int n,k;
int a[100007];

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
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
    }


void solve()
    {
	int i;
	for(i=0;i<n;i++)
		{
		if(a[i]<0)
			{
			if(k>0)
				{
				k--;
				a[i]=a[i]*(-1);
				}
			else break;
			}
		}
	sort(a,a+n);
	k=k%2;
	if(k==1)
		{
		a[0]=a[0]*(-1);
		}
	long long sm=0;
	for(i=0;i<n;i++)
		{
		sm+=a[i];
		}
	cout<<sm<<"\n";
    }