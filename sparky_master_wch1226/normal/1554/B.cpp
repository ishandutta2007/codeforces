#include<bits/stdc++.h>
using namespace std;
vector<int>k(1e5 + 10);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int m;int n; cin >> n; cin >> m;
		for (int i = 1; i <= n; i++)
			cin >> k[i];
		long long int result =-1e12;
		for (int i =max(1,n-2*m); i <= n; i++)
		{
			for (int j =i+1; j <= n; j++)
			{
			    if(j>=n-2*m)
				result = max(result,1LL*i*j-1ll*m*(k[i]|k[j]));
			}
		}
		cout << result << "\n";
	}
}