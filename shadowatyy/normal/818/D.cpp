#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 100007
#define A 1000007

int n, a;

int c[N];

set<int> S;

int ile[A];
int pref[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		S.insert(c[i]);
	}

	if(S.find(a)!=S.end())
		S.erase(a);

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = ++ile[c[i]];

		if(c[i]==a)
			curr = pref[i];
		else if(pref[i]<=curr && S.find(c[i])!=S.end())
			S.erase(c[i]);
	}

	while(!S.empty())
	{
		if(ile[*S.begin()]<curr)
			S.erase(S.begin());
		else
			break;
	}

	if(S.empty())
		cout << -1;
	else
		cout << *S.begin();
}