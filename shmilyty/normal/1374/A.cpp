#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int x,y,n;
		scanf("%d%d%d",&x,&y,&n);
		int ans=(n/x)*x+y;
		if(ans>n)
			ans-=x;
		cout<<ans<<endl;
	}	
	return 0;
}