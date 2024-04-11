//Virtual Participation
//Coder:zpl
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	int n,m,ans,tmp;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) 
		{
			cin>>tmp;
			ans+=tmp;
		}
		ans<<=1;
		if(n==2 or m<n) 
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
		for(int i=1;i<n;i++) printf("%d %d\n", i, i + 1);
		printf("%d %d\n", n, 1);
	}
	return 0;
}