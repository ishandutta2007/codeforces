#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1007;

int n;

int s[N];

VI vec;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		vec.pb(i);

		for(int j = 0; j < 4; ++j)
		{
			int x;
			cin >> x;
			s[i] += x;
		}
	}

	sort(ALL(vec), [](int a, int b)
	{
		if(s[a]==s[b])
			return a<b;
		else
			return s[a]>s[b];
	});

	for(int i = 0; i < n; ++i)
	{
		if(vec[i]==1)
		{
			cout << i+1 << endl;
			exit(0);
		}
	}
}