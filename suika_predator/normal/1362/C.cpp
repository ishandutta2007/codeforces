#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long x;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>x;
		cout<<x*2-__builtin_popcountll(x)<<endl;
	}
	return 0;
}