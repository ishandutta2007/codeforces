#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
/*bool Isprime(int x)
{
	if(x<=1)return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}*/
//vector<int> factor;
int solve(int n)
{
//	cout<<"solve "<<n<<endl;
	int t=n,s=sqrt(n),last=0;
	for(int i=2;i<=s;i++)
	{
		while(n%i==0)
		{
//			factor.push_back(i);
			n/=i;
			last=i;
		}
		s=sqrt(n);
	}
	if(t!=n)
		return t-max(n,last)+1;
	else return t;
}
int main()
{
	scanf("%d",&n);
	int t=n,s=sqrt(n),last=0;
	for(int i=2;i<=s;i++)
	{
		while(n%i==0)
		{
//			factor.push_back(i);
			n/=i;
			last=i;
		}
		s=sqrt(n);
	}
//	if(n!=1)factor.push_back(n);
	int qwq=t-max(n,last);
	int minn=t;
	for(int i=qwq+1;i<=t;i++)
	{
		minn=min(minn,solve(i));
	}
	printf("%d\n",minn);
	return 0;
}