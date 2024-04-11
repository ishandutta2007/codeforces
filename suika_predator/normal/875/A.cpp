#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int n,m;
vector<int> v;
inline int s(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=max(0,n-1000);i<=n;i++)
	{
		if(s(i)+i==n)
		{
			v.push_back(i);
		}
	}
	printf("%d\n",v.size());
	for(auto x:v)printf("%d ",x);
	return 0;
}