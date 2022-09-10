#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
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

const int N = 2e5+7;

int h;

int a[N];

VI A, B;

void wypisz()
{
	cout << "ambiguous\n";

	A.pb(0);
	B.pb(0);

	int last = A.size();

	for(int i = 1; i <= h; ++i)
	{
		if(a[i-1]>1 && a[i-1]>1)
		{
			for(int j = 1; j <= a[i]; ++j)
			{
				if(j==1)
					A.pb(last-1);
				else
					A.pb(last);

				B.pb(last);
			}
		}
		else
		{
			for(int j = 1; j <= a[i]; ++j)
			{
				A.pb(last);
				B.pb(last);
			}
		}

		last = A.size();
	}

	for(auto it:A)
		cout << it << " ";

	cout << endl;

	for(auto it:B)
		cout << it << " ";

	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> h;

	for(int i = 0; i <= h; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= h; ++i)
	{
		if(a[i-1]>1 && a[i]>1)
		{
			wypisz();
			return 0;
		}
	}

	cout << "perfect\n";
}