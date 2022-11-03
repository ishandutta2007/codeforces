#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define INT long long
using namespace std;

int n;
int sushus[15]={2,3,5,7,11,13,17,19,23,29,31,37};
INT minx=-1;
int cnbb=0;

INT powll(int a,int b)
{
	if(pow(a,b)>1e18)return -1;
	INT ans=1;
	for(int i=0;i<b;i++)ans*=a;
	return ans;
}

INT dfs(int a,int up,int k)
{
	if(a==1)return 1;
	if(k>=12)return -1;
	INT ans=-1;
	for(int i=2;i<=up;i++)
		if(a%i==0)
		{
			INT p=powll(sushus[k],i-1);
			if(p<0)continue;
			INT q=dfs(a/i,i,k+1);
			if(q<0)continue;
			if(1.0*p*q>1e18)continue;
			if(ans<0||ans>=p*q)ans=p*q;
		}
	return ans;
}

int main()
{
	cin>>n;
	cout<<dfs(n,n,0)<<endl;
	return 0;
}