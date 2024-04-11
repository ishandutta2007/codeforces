#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int a[n],p[n];
	for(i=0;i<n;i++)
	cin>>a[i]>>p[i];
	i=1;
	long long cost=a[0]*p[0];
	while(i<n)
	{
		if(p[i]>p[i-1])
		{
			p[i]=p[i-1];
		}
		cost+=p[i]*a[i];
		i++;
	}
	cout<<cost;
}