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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+7;

int n, q, ile;

int a[N];

set<int> S[N];
ordered_set<int> U;

int seg(int a, int b)
{
	auto l = U.lower_bound(a);

	if(l==U.end())
		return 0;

	auto r = U.upper_bound(b);
	--r;
	return U.order_of_key(*r)-U.order_of_key(*l)+1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	int f = -1;
	int jestq = -1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i])
		{
			++ile;
			S[a[i]].insert(i);
			U.insert(i);

			if(f==-1)
				f = a[i];

			if(a[i]==q)
				jestq = i;
		}
	}

	if(ile==0)
	{
		cout << "YES" << endl;

		for(int i = 1; i <= n; ++i)
		{
			cout << q << " ";
		}

		cout << endl;
		return 0;
	}

	for(int i = q; i >= 1; --i)
	{
		if(S[i].empty())
			continue;
		else 
		{
			int l = *S[i].begin();
			int r = *S[i].rbegin();

			if(seg(l, r)!=S[i].size())
			{
				cout << "NO" << endl;
				return 0;
			}

			for(auto it:S[i])
			{
				U.erase(it);
			}
		}
	}

	if(ile==n)
	{	
		if(jestq==-1)
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			cout << "YES" << endl;

			for(int i = 1; i <= n; ++i)
			{
				cout << a[i] << " ";
			}

			cout << endl;
			return 0;
		}
	}	

	if(jestq==-1)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(a[i]==0)
			{
				a[i] = q;
				break;
			}
		}
	}

	cout << "YES" << endl;

	int l = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(a[i])
		{
			cout << a[i] << " ";
			l = a[i];
		}
		else
		{
			if(l==-1)
				cout << f << " ";
			else
				cout << l << " ";
		}
	}
}