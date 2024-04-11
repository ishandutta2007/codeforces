#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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

#define M 1000003

int c, w, h, ans;

vector<VLL> operator*(const vector<VLL> &a, const vector<VLL> &b)
{
	vector<VLL> c(w+1, VLL(w+1, 0));

	for(int i = 0; i < w+1; ++i)
	{
		for(int j = 0; j < w+1; ++j)
		{
			for(int k = 0; k < w+1; ++k)
			{
				c[i][j] += a[i][k]*b[k][j];
			}

			c[i][j] %= M;
		}
	}

	return c;
}

vector<VLL> pot(vector<VLL> A, int w)
{	
	auto R = A;
	--w;

	for(int i = 0; i < 30; ++i)
	{
		if(w&(1<<i))
			R = R*A;

		A = A*A;
	}

	return R;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> c >> w >> h;

	vector<VLL> A(w+1, VLL(w+1, 0));

	for(int i = 0; i < w+1; ++i)
	{
		A[0][i] = 1;
	}

	for(int i = 0; i < w; ++i)
	{
		A[1+i][i] = h;
	}

	auto R = pot(A, c);

	for(int i = 0; i < w+1; ++i)
	{
		ans += R[i][0];
	}

	cout << ans%M;
}