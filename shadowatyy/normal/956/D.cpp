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

#define int long long
const int N = 2e5+7;
const int M = 1<<18;
const double eps = 1e-9;

int n, w, ans;

int x[N];
int v[N];

PII l[N];
PII r[N];

int L[N];
int R[N];

vector<PII> val;

VI A, B;

VI poczA[N];
VI poczB[N];

struct tree
{
	int load[2*M];

	void insert(int a)
	{
		a += M;

		while(a)
		{
			++load[a];
			a /= 2;
		}
	}

	int query(int a, int b)
	{
		if(a>b)
			return 0;

		a += M;
		b += M;

		int res = load[a];

		if(a!=b)
			res += load[b];

		while(a<b-1)
		{
			if(a%2==0)
				res += load[a+1];

			if(b%2==1)
				res += load[b-1];

			a /= 2;
			b /= 2;
		}

		return res;
	}
};

tree tA, tB;

bool comp(PII a, PII b)
{
	return a.st*b.nd<b.st*a.nd;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> w;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> v[i];

		l[i] = mp(abs(x[i]), abs(v[i])+w);
		r[i] = mp(abs(x[i]), abs(v[i])-w);

		val.pb(l[i]);
		val.pb(r[i]);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());
	sort(ALL(val), comp);

	for(int i = 1; i <= n; ++i)
	{
		L[i] = lower_bound(ALL(val), l[i], comp)-val.begin()+1;
		R[i] = lower_bound(ALL(val), r[i], comp)-val.begin()+1;

		if(x[i]<0)
			poczA[L[i]].pb(i);
		else
			poczB[L[i]].pb(i);
	}

	for(int i = 1; i <= 2*n; ++i)
	{
		sort(ALL(poczA[i]), [](int a, int b)
		{
			return R[a]>R[b];
		});

		sort(ALL(poczB[i]), [](int a, int b)
		{
			return R[a]>R[b];
		});

		for(auto it:poczA[i])
		{
			ans += tA.query(R[it], 2*n);
			tA.insert(R[it]);
		}

		for(auto it:poczA[i])
		{
			ans += tB.query(L[it], 2*n);
		}

		for(auto it:poczB[i])
		{
			ans += tA.query(L[it], 2*n);
		}

		for(auto it:poczB[i])
		{
			ans += tB.query(R[it], 2*n);
			tB.insert(R[it]);
		}
	}

	cout << ans << endl;
}