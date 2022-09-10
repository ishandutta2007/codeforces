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
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 107;

int n, a;

map<int, VI> P;
map<VI, int> F;

void solve(VI v)
{
	if(F.find(v)!=F.end())
		return;

	VI os;

	for(int i = 1; i <= v[0]; ++i)
	{
		VI curr = v;

		for(auto &it:curr)
		{
			if(it>=i)
				it -= i;
		}

		sort(ALL(curr), greater<int>());

		while(!curr.empty() && curr.back()==0)
			curr.pop_back();

		solve(curr);
		os.pb(F[curr]);
	}

	sort(ALL(os));
	os.erase(unique(ALL(os)), os.end());

	if(os[0]!=0)
		F[v] = 0;
	else
	{
		for(int i = 0; i+1 < os.size(); ++i)
		{
			if(os[i]+1!=os[i+1])
			{
				F[v] = os[i]+1;
				return;
			}
		}

		F[v] = os.back()+1;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a;

		int curr = a;

		for(int j = 2; j*j <= a; ++j)
		{
			if(curr%j==0)
			{
				int ile = 0;

				while(curr%j==0)
				{
					++ile;
					curr /= j;
				}

				P[j].pb(ile);
			}
		}

		if(curr>1)
			P[curr].pb(1);
	}

	F[VI()] = 0;

	for(auto &it:P)
	{
		sort(ALL(it.nd));
		it.nd.erase(unique(ALL(it.nd)), it.nd.end());
		sort(ALL(it.nd), greater<int>());
		solve(it.nd);
	}

	int res = 0;

	for(auto it:P)
	{
		res ^= F[it.nd];
	}

	if(res)
		cout << "Mojtaba";
	else
		cout << "Arpa";
}