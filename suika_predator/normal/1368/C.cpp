#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	cout<<3*n+4<<endl;
	for(int i=1;i<=n+1;i++)
	{
		cout<<i-1<<' '<<i-1<<endl;
		cout<<i<<' '<<i-1<<endl;
		cout<<i-1<<' '<<i<<endl;
	}
	cout<<n+1<<' '<<n+1<<endl;
	return 0;
}