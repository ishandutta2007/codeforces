#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t,n1,n2;
	cin>>t;
	while(t--)
	{
		cin>>n1>>n2;
		if(n1==0||n2==0)throw;
		int d=cbrt(1ll*n1*n2)+0.5;
		if(1ll*d*d*d==1ll*n1*n2&&n1%d==0&&n2%d==0)puts("Yes");
		else puts("No");
	}
	return 0;
}