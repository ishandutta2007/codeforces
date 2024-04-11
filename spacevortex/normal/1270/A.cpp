#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main()
{
	ll T,n,k1,k2,x,pd;
	cin>>T;
	while(T--)
	{
		cin>>n>>k1>>k2;
		pd=0;
		while(k1--)
		{
			cin>>x;if(x==n) pd=1;
		}
		while(k2--) cin>>x;
		if(pd) puts("YES");
		else puts("NO");
	}
	return 0;
}