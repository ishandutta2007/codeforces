#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		if(a<c)cout<<1<<' ';
		else cout<<-1<<' ';
		if(1ll*a*b>c)cout<<b<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}