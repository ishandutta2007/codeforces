#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	vector<pair<int,int>> s;
	for (int i = 0; i < q; i++)
	{
		int typ, id;
		cin >> typ >> id;
		if (typ == 1)
		{
			s.push_back({t[id-1], id});
			if (s.size() > min(k, n))
			{
				sort(s.begin(), s.end());
				s.erase(s.begin());
			}
		}
		else if (typ == 2)
		{
			bool online = false;
			for (auto x : s)
			{
				if (x.second == id)
				{
					online = true;
					break;
				}
			}
			cout << (online ? "YES" : "NO") << endl;
		}
	}
	exit(0);
}