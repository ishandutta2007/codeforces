#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	cin>>str;
	int n=str.length();
	vector<long long> f(n+5),g(n+5);
	int lb=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='a')
		{
			f[i]=(1+g[lb])%MOD;
		}
		else if(str[i-1]=='b')
		{
			lb=i;
		}
		g[i]=(f[i]+g[i-1])%MOD;
	}
	cout<<g[n]<<endl;
	return 0;
}