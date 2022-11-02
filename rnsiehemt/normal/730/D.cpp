#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, r;
ll l[512123];
ll t[512123];

int main()
{
	cin >> n >> r;
	for (ll i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	for (ll i = 0; i < n; i++)
	{
		cin >> t[i];
	}

	ll ans = 0;
	vector<ll> sols;
	ll rem = 0;
	ll ctime = 0;
	for (ll i = 0; i < n; i++)
	{
		if (t[i] < l[i])
		{
			cout << "-1\n";
			return 0;
		}
		if (rem) {
			if (rem >= l[i])
			{
				rem -= l[i];
				ctime += l[i];
				continue;
			}
			ctime += rem;
			l[i] -= rem;
			t[i] -= rem;
			rem = 0;
		}
		if (t[i] >= 2*l[i]) {
			ctime += 2*l[i];
			continue;
		}
		ctime += (t[i] - l[i])*2;
		l[i] -= t[i] - l[i];
		ans += l[i] / r;
		if (l[i] % r != 0) ans++;
		if (ans <= 100000) {
			for (ll j = ctime; j < ctime + l[i]; j += r)
			{
				sols.push_back(j);
			}
		}
		ctime += l[i];
		rem = (r - l[i] % r) % r;
	}
	cout << ans << '\n';
	if (ans <= 100000)
	for (ll i = 0; i < sols.size(); i++)
	{
		if (i) cout << ' ';
		cout << sols[i];
	}
	cout << '\n';
	return 0;
}