#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 1011111;
const int M = 23;
const int Inf = 0x3f3f3f3f;
typedef long long intl;
typedef long double doublel;

int v[N], c[N];
int calc[N];

int rmax[2][N][M];

int rmq(int t, int l, int r)
{
	/*
	if(l == r)
		return -Inf;
	*/
	int n = 31 - __builtin_clz(r - l);
	//cout << l << ' ' << r << ' ' << n << '\n';
	//cout << rmax[t][l][n] << '\n';
	return max(rmax[t][l][n], /*rmq(t, l + (1 << n), r)*/rmax[t][r - (1 << n)][n]);
}

int get_val(int l, int r)
{
	return min(100 * rmq(0, l, r), -rmq(1, l, r));
}
bool check_val(int l, int r)
{
	return 100 * rmq(0, l, r) < -rmq(1, l, r);
}

doublel log_fac[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
	{
		cin >> v[i];
		rmax[0][i][0] = v[i];
	}
	for(int i = 0; i < n; i ++)
	{
		cin >> c[i];
		rmax[1][i][0] = -c[i];
	}
	for(int t = 0; t < 2; t ++)
		for(int j = 1; j < M; j ++)
			for(int i = 0; i < n; i ++)
				if(i + (1 << j) < N)
					rmax[t][i][j] = max(rmax[t][i][j - 1], rmax[t][i + (1 << (j - 1))][j - 1]);
	/*
	for(int i = 0; i < n; i ++)
		for(int j = i; j <= n; j ++)
		{
			cout << "------\n";
			cout << i << ' ' << j << ' ' << get_val(i, j) << '\n';
		}
	*/
		/*
	int p = 0;
	for(int i = 0; i < n; i ++)
	{
		if(p <= i)
			p ++;
		while(p < n && get_val(i, p + 1) >= get_val(i, p))
			p ++;
		calc[i] = get_val(i, p);
		//cout << i << ' ' << p << ' ' << calc[i] << '\n';
	}
	*/
	for(int i = 0; i < n; i ++)
	{
		int left = i + 1, right = n + 1;
		while(left + 1 < right)
		{
			int mid = (left + right) >> 1;
			if(check_val(i, mid))
				left = mid;
			else
				right = mid;
		}
		calc[i] = get_val(i, left);
		if(left != n)
			calc[i] = max(calc[i], get_val(i, left + 1));
	}

	sort(calc, calc + n, greater<int>());
	log_fac[0] = log(1);
	for(int i = 1; i < N; i ++)
		log_fac[i] = log_fac[i - 1] + log(i);

	doublel ans = 0.0;
	for(int i = k - 1; i < n; i ++)
	{
		ans += calc[i] * exp(log_fac[i] - log_fac[k - 1] - log_fac[i - k + 1]
							- (log_fac[n] - log_fac[k] - log_fac[n - k]));
		//cout << exp(log_fac[i] - log_fac[k - 1] - log_fac[i - k + 1]
							//- (log_fac[n] - log_fac[k] - log_fac[n - k])) << '\n';
	}
	cout << setprecision(12) << ans << '\n';
	return 0;
}