#include<bits/stdc++.h>
using namespace std;
int T,n,a,b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b;
		if(a+b<=n)cout<<1<<' ';
		else cout<<min(a+b+1-n,n)<<' ';
		if(a+b<=n+1)cout<<a+b-1<<endl;
		else cout<<n<<endl;
	}
	return 0;
}