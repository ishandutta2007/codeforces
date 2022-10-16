#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		int ans=b-a;
		for(int i=0;i<=b-a;i++)
		{
			//a,b+i
			int t=a|(b+i),tt=(a+i)|b;
			ans=min(ans,i+1+min(t-(b+i),tt-b));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}