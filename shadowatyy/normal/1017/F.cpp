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

using ui = unsigned int;
const int N = 1e8+7;

int n;

ui A, B, C, D, ans;

bitset<100000> prime;

bitset<N> sito;

void solve(int l, int r)
{
	sito.reset();

	for(int i = 2; i*i <= r; ++i)
	{
		if(!prime[i])
		{
			for(int j = max(i*i, (l+i-1)/i*i); j <= r; j += i)
			{
				sito[j-l] = 1;
			}
		}		
	}

	for(int i = l; i <= r; ++i)
	{
		if(!sito[i-l])
		{
			ui ile = 0;

			for(ll j = i; j <= n; j *= i)
			{
				ile += n/j;
			}

			ans += ile*(D+i*(C+i*(B+i*A)));
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> A >> B >> C >> D;

	for(int i = 2; i*i <= n; ++i)
	{
		for(int j = i*i; (ll)j*j <= n; j += i)
		{
			prime[j] = 1;
		}
	}

	for(int i = 2; i <= n; i += 1e8L)
	{
		solve(i, min(n, i+(int)1e8L-1));
	}

	cout << ans << endl;
}