#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 500000007
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

#define N 200007

int n, l = -inf, r = 2*inf;

int c[N];

int d[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i] >> d[i];

		if(d[i]==1)
		{
			l = max(l+c[i], 1900+c[i]);
			r += c[i];
		}

		if(d[i]==2)
		{
			r = min(r+c[i], 1899+c[i]);
			l += c[i];
		}
	}

	if(l>r)
	{
		cout << "Impossible";
		return 0;
	}

	if(r>=inf)
	{
		cout <<"Infinity";
		return 0;
	}

	cout << r;
		
}