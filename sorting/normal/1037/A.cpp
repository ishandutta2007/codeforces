#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#define endl "\n"

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin>>n;

	long long i;

	for(i=0;(1<<i)<=n;i++)
		continue;

	cout<<i<<endl;

	return 0;
}