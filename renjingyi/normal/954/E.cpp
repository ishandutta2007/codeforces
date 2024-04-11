#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, pair<int, int> > pp;
const int maxn = 1e6 + 5;
long long a[maxn];
int t[maxn];
pp asd[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
	long long n, T;
	cin >> n >> T;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> t[i];
	for(int i = 1; i <= n; i ++)
		asd[i] = mp(t[i], mp(a[i], i));
	sort(asd + 1, asd + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		t[i] = asd[i].first;
		a[i] = asd[i].second.first;
	}
	long long s1 = 0, s2 = 0;
	long double ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(t[i] == T)
		{
			s1 += a[i] * t[i];
			s2 += a[i];
		}
		else if(s1 + a[i] * t[i] < (s2 + a[i]) * T)
		{
			s1 += a[i] * t[i];
			s2 += a[i];
		}
		else if(s1 < s2 * T && t[i] > T)
		{
			ans = max(ans, s2 + (long double)(s1 - s2 * T) / (T - t[i]));
			break;
		}
		if(i == n && s1 == s2 * T)
			ans = max(ans, (long double)s2);
	}
	s1 = s2 = 0;
	for(int i = n; i >= 1; i --)
	{
		if(t[i] == T)
		{
			s1 += a[i] * t[i];
			s2 += a[i];
		}
		else if(s1 + a[i] * t[i] > (s2 + a[i]) * T)
		{
			s1 += a[i] * t[i];
			s2 += a[i];
		}
		else if(s1 > s2 * T && t[i] < T)
		{
			ans = max(ans, s2 + (long double)(s1 - s2 * T) / (T - t[i]));
			break;
		}
		if(i == 1 && s1 == s2 * T)
			ans = max(ans, (long double)s2);
	}
	printf("%.10lf\n", (double)ans);
	
	return 0;
}
/*
20 30
70 97 14 31 83 22 83 56 19 87 59 7 7 89 24 82 34 40 6 24
10 4 47 46 11 18 32 55 16 32 53 37 43 32 41 46 57 14 60 44
*/