#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#define endl "\n"

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n,res=0;

	string a,b;

	cin>>n>>a>>b;

	long long i;

	for(i=0;i<n-1;i++)
		if(a[i]!=b[i] && a[i+1]!=b[i+1] && a[i]!=a[i+1])
		{
			a[i]=b[i];
			a[i+1]=b[i+1];
			res++;
		}

	for(i=0;i<n;i++)
		if(a[i]!=b[i])
			res++;

	cout<<res<<endl;

	return 0;
}