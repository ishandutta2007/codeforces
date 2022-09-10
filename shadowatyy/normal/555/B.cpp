#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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

#define N 200007
#define int long long

int n, m;

int l[N], r[N], d[N], A[N], B[N], res[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return d[a]<d[b];
	}
};

bool cmp(int a, int b)
{
	return B[a]<B[b];
}

multiset<int, comp> S;
VI v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
	}

	for(int i = 1; i < n; ++i)
	{
		A[i] = l[i+1]-r[i];
		B[i] = r[i+1]-l[i];
		v.pb(i);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> d[i];
		S.insert(i);
	}

	sort(ALL(v), cmp);

	for(auto it:v)
	{
		d[0] = A[it];

		if(S.lower_bound(0)==S.end() || d[*S.lower_bound(0)]>B[it])
		{
			cout << "No";
			return 0;
		}

		res[it] = *S.lower_bound(0);
		S.erase(S.lower_bound(0));
	}

	cout << "Yes\n";

	for(int i = 1; i < n; ++i)
	{
		cout << res[i] << " ";
	}
}