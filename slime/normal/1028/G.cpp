#include <bits/stdc++.h>
#define ll long long
#include <vector> 
using namespace std;
ll M = 10004205361450474;
ll ca[6];
ll dp[10005][6];
ll caldp(ll a, int b)
{
	if(a >= 10000)
		return a + ca[b] - 1;
	else return dp[a][b];
}
void work(ll a, ll b, int tms)
{
	ll ns = a;
	ll tr = min(a, (ll)10000);
	cout<<tr<<" ";
	for(int i = 1; i <= tr; i++)
		cout<<caldp(ns, tms - 1) + 1<<" ", 
		ns = caldp(ns, tms - 1) + 2;
	fflush(stdout);
	int res;
	cin>>res;
	if(res == -1) return;
	ns = a;
	for(int i = 1; i <= tr; i++)
	{
		if(res == i - 1)
			work(ns, caldp(ns, tms - 1), tms - 1);
		ns = caldp(ns, tms - 1) + 2;
	}
	if(res == tr) 
		work(ns, caldp(ns, tms - 1), tms - 1);
}
int main()
{
	ca[0] = 0;
	for(int i = 1; i <= 5; i++)
		ca[i] = ca[i - 1] * 10001 + 10000;
//	cout<<"ASFD"<<endl;
	for(int i = 0; i <= 5; i++)
		for(int j = 1; j <= 10000; j++)
		{
			if(i >= 5 && j >= 2) break;
			//cout<<"WWW"<<i<<" "<<j<<endl;
			if(i == 0) dp[j][i] = j - 1;
			else
			{
				ll ns = j - 1;
				for(int t = 1; t <= j; t++)
				{
					ns = caldp(ns + 1, i - 1) + 1; //cout<<"!!!!"<<ns<<endl;
//					if(j == 2) cout<<i<<" "<<t<<" "<<ns<<endl;
				}
				ns = caldp(ns + 1, i - 1);
				dp[j][i] = ns;
			}
		}
//	cout<<dp[2][1]<<endl;
//	cout<<dp[1][5]<<endl;
	work(1, M, 5);
	return 0;
}