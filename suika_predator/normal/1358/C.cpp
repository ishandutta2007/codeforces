#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		cout<<1ll*(c-a)*(d-b)+1<<endl;
	}
	return 0;
}