#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 400005
#define ld double
#define mod 998244353
using namespace std;
int a[maxn];
int n, s;
int r[maxn], rcnt = 0;
int sm[maxn];
int main()
{
	cin >> n >> s;
	for (int j = 1; j <= n; j++)
		scanf("%d", &a[j]);
	sort (a + 1, a + n + 1);
	s = (s * 8 / n);
	int mn = 1;
	for (int j = 1; j <= min(s, 100); j++) {
		mn = min(n, mn * 2);
	} 
	for (int j = 1; j <= n; ) {
		int k = j;
		while (a[k] == a[j] && k <= n) k++;
		r[rcnt++] = k - j;
		j = k; 
	}
	mn = min(mn, rcnt);
	sm[0] = r[0];
//	cout << r[0] << " " << r[1] << " " << r[2] << endl;
	for (int j = 1; j < rcnt; j++)
		sm[j] = sm[j - 1] + r[j];
	int ans = 0;
	for (int j = 0; j < rcnt; j++) {
		int ll = j, rr = min(rcnt - 1, j + mn - 1);
		int ss = sm[rr];
		if (ll) ss -= sm[ll - 1];
		ans = max(ans, ss);
	}
	cout << n - ans << endl;
	return 0;
}