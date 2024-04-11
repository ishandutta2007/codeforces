#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 2011;
const int M = 5011;

int a[N];
double p[N];
double sp[M];
double pp[M * 2];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	map <int, double> mp;
	for(int i = 1; i <= n; i ++)
		p[i] = (double)(i - 1) / (n * (n - 1) / 2);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j < i; j ++)
			sp[a[i] - a[j]] += 1.0 / (n * (n - 1) / 2);
	/*
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			mp[a[i] + a[j]] += p[i] * p[j];
	*/
	for(int i = 1; i <= 5000; i ++)
		for(int j = 1; j <= 5000; j ++)
			pp[i + j] += sp[i] * sp[j];

	/*
	int m = mp.size();
	for(auto it = mp.begin(); it != mp.end(); it ++)
		pp[it -> first] = it -> second;
	*/
	for(int i = 1; i < M * 2; i ++)
		pp[i] += pp[i - 1];

	double ans = 0;
	for(int i = 1; i <= 5000; i ++)
		ans += sp[i] * pp[i - 1];
	cout << setprecision(8) << ans << '\n';
	return 0;
}