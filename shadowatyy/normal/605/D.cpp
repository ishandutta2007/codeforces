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

const int N = 1e5+7;
const int M = 1<<18;

int n;

int A[N];
int B[N];
int C[N];
int D[N];

int dist[N];
int p[N];

queue<int> Q;

VI X[2*N];
int curr[2*N];

VI val, res;

PII load[2*M];

void insert(int a, int v)
{
	a += M;
	load[a] = mp(v, a-M);
	a /= 2;

	while(a>=1)
	{
		load[a] = min(load[2*a], load[2*a+1]);
		a /= 2;
	}
}

PII query(int a, int b)
{
	a += M;
	b += M;

	PII res = min(load[a], load[b]);

	while(a<b-1)
	{
		if(a%2==0)
			res = min(res, load[a+1]);

		if(b%2==1)
			res = min(res, load[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

bool comp(int a, int b)
{
	return B[a]<B[b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		val.pb(A[i]);
		val.pb(C[i]);
	}

	val.pb(0);
	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 1; i <= n; ++i)
	{
		A[i] = lower_bound(ALL(val), A[i])-val.begin();
		C[i] = lower_bound(ALL(val), C[i])-val.begin();
		X[A[i]].pb(i);
	}

	for(int i = 0; i <= 2*n; ++i)
	{
		sort(ALL(X[i]), comp);
	}

	for(int i = 0; i < 2*M; ++i)
	{
		load[i] = mp(inf, inf);
	}

	for(int i = 0; i <= 2*n; ++i)
	{
		if(curr[i]!=X[i].size())
			insert(i, B[X[i][curr[i]]]);
	}

	memset(dist, inf16, sizeof dist);

	dist[0] = 0;
	Q.push(0);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		PII q = query(0, C[v]);

		while(q.st<=D[v])
		{
			p[X[q.nd][curr[q.nd]]] = v;
			dist[X[q.nd][curr[q.nd]]] = dist[v]+1;
			Q.push(X[q.nd][curr[q.nd]]);

			if(++curr[q.nd]==X[q.nd].size())
				insert(q.nd, inf);
			else
				insert(q.nd, B[X[q.nd][curr[q.nd]]]);

			q = query(0, C[v]);
		}
	}

	if(dist[n]==inf16)
	{
		cout << -1;
		return 0;
	}

	int v = n;

	while(v)
	{
		res.pb(v);
		v = p[v];
	}

	reverse(ALL(res));

	cout << res.size() << endl;

	for(auto it:res)
		cout << it << " ";
}