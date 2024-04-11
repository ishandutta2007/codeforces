#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
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

int m, n;

int ask(int x)
{
	cout << x << endl;
	fflush(stdout);
	int ans;
	cin >> ans;

	if(ans==0)
		exit(0);

	return ans;
}

int ok[37];

int32_t main()
{
	cin >> m >> n;

	for(int i = 0; i < n; ++i)
	{
		int q = ask(1);

		if(q==1)
			ok[i] = 1;
		else
			ok[i] = -1;
	}

	int l = 1, r = m, curr = 0;

	while(l<r)
	{
		int m = (l+r)/2;
		int q = ok[curr]*ask(m);

		if(q==-1)
			r = m-1;
		else
			l = m+1;

		curr = (curr+1)%n;
	}

	ask(l);
}