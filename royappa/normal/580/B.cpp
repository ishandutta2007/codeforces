#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
typedef long long LL;

int main() {
	int n, d;
	cin >> n >> d;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int m, f;
		cin >> m >> f;
		v[i] = make_pair(m, f);
	}
	sort(v.begin(), v.end());
	vector<LL> t(n);
	for (int i = 0; i < n; i++)
	{
		t[i] = v[i].second;
	}
	for (int i = n-2; i >= 0; i--)
	{
		t[i] += t[i+1];
	}
	LL best = 0;
	for (int i = 0; i < n; i++)
	{
		int x = v[i].first+d-1;
		pair<int,int> z = make_pair(x, 2000000000);
		int p = upper_bound(v.begin(), v.end(), z) - v.begin();
		LL ff = (p == n) ? t[i] : t[i]-t[p];
		best = max(ff, best);
	}
	cout << best << endl;
	return 0;
}