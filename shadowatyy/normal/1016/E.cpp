#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 2e5+7;

int sy, a, b, n, q;

int l[N];
int r[N];
int sum[N];

bool prawo(int x1, int y1, int x2, int y2)
{
	return x1*y2-x2*y1>0;
}

double query(int x, int y)
{
	int lo = 1, hi = n+1, L = -1, R = -1;

	while(lo<hi)
	{
		int m = (lo+hi)/2;

		if(hi==m)
			--m;

		if(prawo(a-x, sy-y, r[m]-x, 0-y))
			hi = m;
		else
			lo = m+1;
	}

	L = lo;
	lo = 0, hi = n;

	while(lo<hi)
	{
		int m = (lo+hi)/2;

		if(lo==m)
			++m;

		if(prawo(l[m]-x, 0-y, b-x, sy-y))
			lo = m;
		else
			hi = m-1;
	}

	R = lo;

	if(L>R)
		return 0;

	if(L==R)
	{
		double X1 = max((double)l[L], a*(double)y/(y-sy) + x*(double)-sy/(y-sy));
		double X2 = min((double)r[R], b*(double)y/(y-sy) + x*(double)-sy/(y-sy));
		double ans = X2-X1;
		ans *= (double)(y-sy)/y;
		return ans;
	}

	double ans = sum[R-1]-sum[L];

	double X1 = max((double)l[L], a*(double)y/(y-sy) + x*(double)-sy/(y-sy));
	double X2 = min((double)r[R], b*(double)y/(y-sy) + x*(double)-sy/(y-sy));

	ans += r[L]-X1;
	ans += X2-l[R];

	ans *= (double)(y-sy)/y;
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cout << fixed << setprecision(15);

	cin >> sy >> a >> b >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
		sum[i] = sum[i-1] + r[i] - l[i];
	}

	cin >> q;

	while(q--)
	{
		int x, y;
		cin >> x >> y;
		cout << query(x, y) << endl;
	}
}