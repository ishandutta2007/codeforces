#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m;
			if(i%2==0)cout<<abs(m)<<' ';
			else cout<<-abs(m)<<' ';
		}
		cout<<endl;
	}
	return 0;
}