#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

int n;

int wypisz(int x, int y)
{
	cout << x << " " << y << endl;
	fflush(stdout);
	string s;
	cin >> s;

	if(s=="black")
		return 1;
	else
		return 0;
}

int32_t main()
{
	cin >> n;

	int lewy = wypisz(0, 1);
	int l = 0, r = 1e9;

	for(int i = 2; i <= n; ++i)
	{
		int x = (l+r)/2;
		int c = wypisz(x, 1);

		if(c==lewy)
			l = x;
		else
			r = x;
	}

	cout << l << " " << 0 << " " << r << " " << 2 << endl;
	fflush(stdout);
}