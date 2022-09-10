#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1<<19;

int n, r;

double sum;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cout << fixed << setprecision(15);

	cin >> n >> r;

	for(int i = 0; i < 1<<n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	cout << sum/(1<<n) << endl;

	while(r--)
	{
		int ind, v;
		cin >> ind >> v;
		sum -= a[ind];
		a[ind] = v;
		sum += a[ind];

		cout << sum/(1<<n) << endl;
	}
}