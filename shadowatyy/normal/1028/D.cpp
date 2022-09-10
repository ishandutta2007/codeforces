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

const int mod = 1e9+7;
const int N = 4e5+7;

int n, ans = 1;

set<int> lo, hi, mi;

string s[N];

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i] >> a[i];

		if(s[i]=="ADD")
		{
			if(!hi.empty() && *hi.begin()<a[i])
				hi.insert(a[i]);
			else if(!lo.empty() && *lo.rbegin()>a[i])
				lo.insert(a[i]);
			else
				mi.insert(a[i]);
		}
		else
		{
			if(hi.find(a[i])!=hi.end())
			{
				if(*hi.begin()!=a[i])
				{
					cout << 0 << endl;
					return 0;
				}

				hi.erase(a[i]);

				for(auto it:mi)
					lo.insert(it);

				mi.clear();
			}
			else if(lo.find(a[i])!=lo.end())
			{
				if(*lo.rbegin()!=a[i])
				{
					cout << 0 << endl;
					return 0;
				}

				lo.erase(a[i]);

				for(auto it:mi)
					hi.insert(it);

				mi.clear();
			}
			else
			{
				for(auto it:mi)
				{
					if(it>a[i])
						hi.insert(it);
					else if(it<a[i])
						lo.insert(it);
				}

				mi.clear();
				ans = 2*ans%mod;
			}
		}
	}

	ans = (ll)ans*(mi.size()+1)%mod;
	cout << ans << endl;
}