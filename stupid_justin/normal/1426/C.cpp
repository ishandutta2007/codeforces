
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,q;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>a;
		q=floor(sqrt(a));
		if (q*q==a) cout<<q*2-2<<endl;
		else if (q*(q+1)>=a) cout<<q*2-1<<endl;
		else cout<<q*2<<endl;
	}
}