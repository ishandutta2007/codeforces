#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m,k;
int a[150];


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
	scanf("%d%d%d",&n,&m,&k);
	int i;
	for(i=0;i<n;i++)
		{
		scanf("%d",&a[i]);
		}
    }


void solve()
    {
	sort(a,a+n);
	int i;
	int br=0;
	int s=k;
	for(i=n-1;i>=0;i--)
		{
		if(s>=m)
			{
			printf("%d\n",br);
			return ;
			}
		br++;
		s+=a[i];
		s--;
		}
		if(s>=m)
			{
			printf("%d\n",br);
			return ;
			}
	printf("-1\n");
    }