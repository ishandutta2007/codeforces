#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m;
int x, y, z;
vector<vector<int> > a;
vector<int> s1, s2;
vector<int> p1, p2;

int sum1(int l, int r){
	if (r < l)
		return 0;
	if (l == 0)
		return p1[r];
	return p1[r] - p1[l-1];
}

int sum2(int l, int r){
	if (r < l)
		return 0;
	if (l == 0)
		return p2[r];
	return p2[r] - p2[l-1];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i].resize(m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	s1.assign(n, 0); s2.assign(m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			s1[i] += a[i][j];
			s2[j] += a[i][j];
		}
	p1.assign(n, 0);
	p1[0] = s1[0];
	for (int i = 1; i < n; i++)
		p1[i] = p1[i-1] + s1[i];
	p2.assign(m, 0);
	p2[0] = s2[0];
	for (int i = 1; i < m; i++)
		p2[i] = p2[i-1] + s2[i];
	cin >> x >> y >> z;
	int res = 0;
	for (int l1 = 1; l1 < n; l1++)
		for (int l2 = l1 + 1; l2 < n; l2++){
			int v1 = sum1(0, l1-1), v2 = sum1(l1, l2-1), v3 = sum1(l2, n-1);
			bool flag = ((v1 == x && v2 == y && v3 == z) || (v1 == x && v2 == z && v3 == y));
			flag = flag || (v1 == y && v2 == x && v3 == z);
			flag = flag || (v1 == y && v2 == z && v3 == x);
			flag = flag || (v1 == z && v2 == x && v3 == y);
			flag = flag || (v1 == z && v2 == y && v3 == x);
			if (flag)
				res++;
		}
	for (int l1 = 1; l1 < m; l1++)
		for (int l2 = l1 + 1; l2 < m; l2++){
			int v1 = sum2(0, l1-1), v2 = sum2(l1, l2-1), v3 = sum2(l2, m-1);
			bool flag = ((v1 == x && v2 == y && v3 == z) || (v1 == x && v2 == z && v3 == y));
			flag = flag || (v1 == y && v2 == x && v3 == z);
			flag = flag || (v1 == y && v2 == z && v3 == x);
			flag = flag || (v1 == z && v2 == x && v3 == y);
			flag = flag || (v1 == z && v2 == y && v3 == x);
			if (flag)
				res++;
		}
	cout << res << endl;
    return 0;
}