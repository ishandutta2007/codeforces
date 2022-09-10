#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

int n, x;

int t[57];

string d[57];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	x = 20000;

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> d[i];

		while(t[i]--)
		{
			if(x==0 && d[i]!="North")
			{
				cout << "NO";
				return 0;
			}

			if(x==20000 && d[i]!="South")
			{
				cout << "NO";
				return 0;
			}

			if(d[i]=="North")
				++x;

			if(d[i]=="South")
				--x;
		}	
	}

	if(x!=20000)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES";
}