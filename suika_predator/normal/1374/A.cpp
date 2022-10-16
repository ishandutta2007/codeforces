#include<bits/stdc++.h>
using namespace std;
int T,x,y,n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>n;
		int z=(n-y)/x*x+y;
		cout<<z<<endl;
	}
	return 0;
}