#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

#define N 100007

int n, wyn;

int a[N];

VI res[N];

int sito[N];

void solve(int i)
{
	int l = a[i];

	while(l>1)
	{
		res[sito[l]].pb(i);

		l /= sito[l];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 2; i < N; ++i)
	{
		if(!sito[i])
		{
			for(int j = i; j < N; j += i)
			{
				sito[j] = i;
			}
		}
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		solve(i);
	}

	for(int i = 2; i < N; ++i)
	{
		sort(ALL(res[i]));
		res[i].erase(unique(ALL(res[i])), res[i].end());

		wyn = max(wyn, (int)res[i].size());
	}

	cout << max(wyn, 1);
}