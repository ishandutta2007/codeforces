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

#define y1 nabab
const int N = 57;

int n, m;

int x1[N];
int y1[N];
int x2[N];
int y2[N];
int x[N];
int y[N];
int chce[N];

vector<pair<PII, PII> > ans, rev;

bool wolne(int a, int b)
{
	for(int i = 1; i <= m; ++i)
	{
		if(x[i]==a && y[i]==b)
			return 0;
	}

	return 1;
}	

void solve(vector<pair<PII, PII> > &v)
{
	VI kol;

	for(int i = 1; i <= m; ++i)
	{
		kol.pb(i);
	}

	sort(ALL(kol), [](int a, int b)
	{
		return x[a]<x[b];
	});

	for(int i = 0; i < m; ++i)
	{
		chce[kol[i]] = i+1;
	}

	int ok = 0;

	for(int i = 1; i <= m; ++i)
	{
		if(x[i]==chce[i])
			++ok;
	}

	while(ok<m)
	{
		for(int i = 1; i <= m; ++i)
		{
			if(x[i]!=chce[i])
			{	
				while(x[i]<chce[i] && wolne(x[i]+1, y[i]))
				{
					v.pb({{x[i], y[i]}, {x[i]+1, y[i]}});
					++x[i];
				}

				while(x[i]>chce[i] && wolne(x[i]-1, y[i]))
				{
					v.pb({{x[i], y[i]}, {x[i]-1, y[i]}});
					--x[i];
				}

				if(x[i]==chce[i])
					++ok;
			}
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		while(y[i]<i)
		{
			v.pb({{x[i], y[i]}, {x[i], y[i]+1}});
			++y[i];
		}

		while(y[i]>i)
		{
			v.pb({{x[i], y[i]}, {x[i], y[i]-1}});
			--y[i];
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		while(x[i]<i)
		{
			v.pb({{x[i], y[i]}, {x[i]+1, y[i]}});
			++x[i];
		}

		while(x[i]>i)
		{
			v.pb({{x[i], y[i]}, {x[i]-1, y[i]}});
			--x[i];
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> x1[i] >> y1[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> x2[i] >> y2[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		x[i] = x1[i];
		y[i] = y1[i];
	}

	solve(ans);

	for(int i = 1; i <= m; ++i)
	{
		x[i] = x2[i];
		y[i] = y2[i];
	}

	solve(rev);
	reverse(ALL(rev));

	for(auto &it:rev)
		swap(it.st, it.nd);

	ans.insert(ans.end(), ALL(rev));

	cout << ans.size() << endl;

	for(auto it:ans)
		cout << it.st.st << " " << it.st.nd << " " << it.nd.st << " " << it.nd.nd << endl;
}