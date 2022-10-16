#include<bits/stdc++.h>
using namespace std;
int T,a,b,n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>n;
		int cnt=0;
		while(a<=n&&b<=n)
		{
			if(a>b)b+=a;
			else a+=b;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}