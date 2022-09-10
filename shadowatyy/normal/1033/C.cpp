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
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1e5+7;

int n;

int p[N];
int ans[N];

VI v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		v.pb(i);
	}

	sort(ALL(v), [](int a, int b)
	{
		return p[a]>p[b];
	});

	for(auto i:v)
	{
		for(int j = i+p[i]; j <= n; j += p[i])
		{
			if(p[j]>p[i] && !ans[j])
				ans[i] = 1;
		}

		for(int j = i-p[i]; j >= 1; j -= p[i])
		{
			if(p[j]>p[i] && !ans[j])
				ans[i] = 1;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i])
			cout << 'A';
		else
			cout << 'B';
	}
}