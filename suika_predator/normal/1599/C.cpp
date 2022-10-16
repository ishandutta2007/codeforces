#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2100;

int n,al;
double P;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>P;
	al=n*(n-1)*(n-2)/6;
	int ans=n;
	for(int i=0;i<=n;i++)
	{
		double temp=0;
		if(i>=1&&n-i-1>=0) temp+=(double)(i*(n-i)*(n-i-1)/2)/al/2;
		if(i>=2) temp+=(double)(i*(i-1)*(n-i)/2)/al;
		if(i>=3) temp+=(double)(i*(i-1)*(i-2)/6)/al;
		if(temp>=P) { ans=i;break; }
	}
	cout<<ans<<endl;
	
	return 0;
}