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

const int N = 607;

int n, c;

int vis[N];
int col[N];
int par[N];
int dep[N];

int pytaj(VI v)
{
	if(v.size()<=1)
		return 0;

	cout << "? " << v.size() << endl;

	for(auto it:v)
		cout << it << " ";

	cout << endl;
	fflush(stdout);

	int ans;
	cin >> ans;
	return ans;
}

VI zla(VI A)
{
	while(A.size()>2)
	{
		VI l, r;

		for(auto it:A)
		{
			if(rand()%2)
				l.pb(it);
			else
				r.pb(it);
		}

		if(pytaj(l))
			A = l;
		else if(pytaj(r))
			A = r;
	}

	return A;
}

int znajdz_kraw(int v)
{
	VI vec;

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			vec.pb(i);
	}

	VI bez = vec;
	VI z = vec;
	z.pb(v);

	if(pytaj(z)>pytaj(bez))
	{
		while(bez.size()>1)
		{
			VI l, r;

			for(int i = 0; i < bez.size()/2; ++i)
			{
				l.pb(bez[i]);
			}

			for(int i = bez.size()/2; i < bez.size(); ++i)
			{
				r.pb(bez[i]);
			}

			z = l;
			z.pb(v);

			if(pytaj(z)>pytaj(l))
				bez = l;
			else
				bez = r;
		}

		return bez[0];
	}
	else
		return -1;
}

void dfs(int v)
{
	vis[v] = 1;
	int u = znajdz_kraw(v);

	while(u!=-1)
	{
		dep[u] = dep[v]+1;
		col[u] = !col[v];
		par[u] = v;
		dfs(u);
		u = znajdz_kraw(v);
	}
}

int32_t main()
{
	cin >> n;

	dfs(1);

	VI A, B;

	for(int i = 1; i <= n; ++i)
	{
		if(col[i])
			A.pb(i);
		else
			B.pb(i);
	}

	if(pytaj(A)==0 && pytaj(B)==0)
	{
		cout << "Y" << " " << A.size() << endl;

		for(auto it:A)
			cout << it << " ";

		cout << endl;
		fflush(stdout);
	}
	else
	{
		srand((ll)new int);

		if(!pytaj(A))
			swap(A, B);

		A = zla(A);
		int a = A[0];
		int b = A[1];

		VI L, R;

		while(a!=b)
		{
			if(dep[a]>dep[b])
			{
				L.pb(a);
				a = par[a];
			}
			else
			{
				R.pb(b);
				b = par[b];
			}
		}

		L.pb(a);
		reverse(ALL(R));
		L.insert(L.end(), ALL(R));

		cout << "N" << " " << L.size() << endl;

		for(auto it:L)
			cout << it << " ";

		cout << endl;
		fflush(stdout);
	}
}