#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;

	h %= 12;
	t1 %= 12;
	t2 %= 12;

	h *= 3600;
	h += m*60+s;
	m *= 720;
	m += s*12;
	s *= 720;
	t1 *= 3600;
	t2 *= 3600;
	bool can = true;
	int n = 12*3600;
	for (int t = t1; t != t2; t = (t+1)%n) {
		if (t == h || t == m || t == s) {
			can = false;
			break;
		}
	}
	if (can) {
		cout << "YES" << endl;
		exit(0);
	}
	can = true;
	for (int t = t1; t != t2; t = ((t-1)%n+n)%n) {
		if (t == h || t == m || t == s) {
			can = false;
			break;
		}
	}
	cout << (can ? "YES" : "NO") << endl;
	exit(0);
}