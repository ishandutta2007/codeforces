#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define V vector
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) { return uniform_int_distribution<int>(a, b)(_gen); }

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	VI ans(4, -1);
	int found = 0;
	int resp;

	VI p(n + 1);
	REP(i, n + 1)
		p[i] = i;

	random_shuffle(p.begin() + 1, p.end(), [](int a) { return rd(0, a - 1); });

	for(int i = 1; i <= n; i++)
	{
		int x = p[i];
		cout << "? " << 1 << " " << x << " " << n << " " << x << endl;

		cin >> resp;
		if(resp % 2 == 1)
		{
			int l = 1, r = n;	
			while(l < r)
			{
				int m = (l + r) / 2;
				cout << "? " << l << " " << x << " " << m << " " << x << endl;
				cin >> resp;
				if(resp % 2 == 1)
					r = m;
				else
					l = m + 1;
			}

			ans[found * 2] = l;
			ans[found * 2 + 1] = x;
			found++;

			if(found == 2)
			{
				cout << "! ";
				for(int x : ans)
					cout << x << " ";
				cout << endl;
				return 0;
			}
		}
	}

	if(found != 0) while(true) {}

	for(int i = 1; i <= n; i++)
	{
		int x = p[i];
		cout << "? " << x << " " << 1 << " " << x << " " << n << endl;

		cin >> resp;
		if(resp % 2 == 1)
		{
			int l = 1, r = n;
			while(l < r)
			{
				int m = (l + r) / 2;
				cout << "? " << x << " " << l << " " << x << " " << m << endl;
				cin >> resp;
				if(resp % 2 == 1)
					r = m;
				else
					l = m + 1;
			}

			ans[found * 2] = x;
			ans[found * 2 + 1] = l;

			found++;

			if(found == 2)
			{
				cout << "! ";
				for(int x : ans)
					cout << x << " ";
				cout << endl;
				return 0;
			}
		}
	}
}