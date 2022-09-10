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
using namespace std;

#define int long long

const int N = 1e5+7;

int n, S, pewne, sum, ile, lepsze_a;

int s[N];
int a[N];
int b[N];

VI os;

int sprawdz(int k)
{
	int curr_a = k*S, curr_b = (ile-k)*S, res = 0;

	for(auto i:os)
	{
		if(a[i])
		{
			int biore_a = min(curr_a, s[i]);
			res += a[i]*biore_a;
			curr_a -= biore_a;
		}
		else
		{
			int biore_b = min(curr_b, s[i]);
			res += b[i]*biore_b;
			curr_b -= biore_b;
		}
	}

	return res;
}

bool comp(int A, int B)
{
	return max(a[A], b[A])>max(a[B], b[B]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> S;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i] >> a[i] >> b[i];

		int p = min(a[i], b[i]);
		pewne += s[i]*p;
		a[i] -= p;
		b[i] -= p;

		sum += s[i];
		os.pb(i);
	}

	sort(ALL(os), comp);

	ile = (sum+S-1)/S;

	for(int i = 1; i <= n; ++i)
	{
		if(a[i])
			lepsze_a += s[i];
	}

	int ile_a = lepsze_a/S;

	cout << pewne+max(sprawdz(ile_a), sprawdz(min(ile_a+1, ile)));
}