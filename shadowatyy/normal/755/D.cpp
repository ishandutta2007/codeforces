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
#define flush fflush(stdout)
using namespace std;

#define M (1<<20)

int n, k;

int load[2*M];

ll res = 1;

void insert(int a)
{
	a += M;

	while(a>=1)
	{
		++load[a];
		a /= 2;
	}
}

int query(int a, int b)
{
	if(a>b)
		return 0;

	a += M;
	b += M;

	int res = load[a];

	if(a!=b)
		res += load[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1];

		if(b%2==1)
			res += load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	k = min(k, n-k);

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(curr+k<n)
			res += 1+query(curr+1, curr+k-1);
		else
			res += 1+query(curr+1, n-1)+query(0, (curr+k)%n-1);

		cout << res << " ";

		insert(curr);
		insert((curr+k)%n);
		curr = (curr+k)%n;
	}
}