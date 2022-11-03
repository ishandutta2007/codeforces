#include <cstdio>
#include <iostream>
using namespace std;

int zdgys(int a,int b)
{
	int tmp;
	while(a%b)
	{
		tmp=a%b;
		a=b;
		b=tmp;
	}
	return b;
}

int zxgbs(int a,int b)
{return a*b/zdgys(a,b);}

int main()
{
	int n,m,z;
	cin>>n>>m>>z;
	int ans=z/zxgbs(n,m);
	cout<<ans<<endl;
	return 0;
}