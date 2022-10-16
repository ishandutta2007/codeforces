#include<bits/stdc++.h>
using namespace std;
double f[2001][2001],p;
int n,t;
int main()
{
	cin>>n>>p>>t;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=t;l++)
			f[i][l]=(f[i-1][l-1]+1)*p+f[i][l-1]*(1-p);
	cout.setf(ios::fixed);
	cout.precision(9);
	cout<<f[n][t];
	return 0;
}