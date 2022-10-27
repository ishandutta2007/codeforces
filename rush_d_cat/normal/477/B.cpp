#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<utility>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const int N=10008;
int n,m,a[10],ans;
int gcd(int x,int y){if(x%y)return gcd(y,x%y);return y;}
int b[N][5];
int main(void)
{
	cin>>n>>m;
	int i,j,k,p,p1,p2,p3;
	k=1;for(i=1;i<=n;i++,k+=6)
	{
		for(j=1;j<=5;j++)a[j]=k+j-1;
		for(j=5;j>=1;j--)
		{
			p3=1;
			for(p1=1;p3&&p1<=5;p1++)if(p1!=j)
			for(p2=p1+1;p3&&p2<=5;p2++)if(p2!=j&&gcd(a[p1],a[p2])!=1)p3=0;
			if(p3){p3=0;for(p=1;p<=5;p++){if(p!=j)b[i][++p3]=a[p];}ans=(j==5?a[4]:a[5]);break;}
		}
	}
	cout<<ans*m;
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=4;j++)cout<<b[i][j]*m<<' ';
	}
	return 0;
}