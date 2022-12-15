#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#define endl "\n"

using namespace std;

const long long N = 2e5+7;

long long a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n,s,res=0;

	cin>>n>>s;

	for(long long i=0;i<n;i++)
		cin>>a[i];

	sort(a,a+n);

	for(long long i=0;i<n/2;i++)
		res+=max((long long)0,a[i]-s);

	for(long long i=n/2+1;i<n;i++)
		res+=max((long long)0,s-a[i]);

	res+=abs(a[n/2]-s);

	cout<<res<<endl;

	return 0;
}