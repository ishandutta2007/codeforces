#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL a, b;

	cin >> a >> b;
	LL x = a;
	vector<int> v;
	while (x) {
		v.push_back(x%10LL);
		x /= 10LL;
	}
	reverse(v.begin(), v.end());
	int n = v.size();
	LL res = 0;
	do {
		int d = -1, p = -1;
		for (int j = 0; j < n; j++) {
			if (res == 0 && v[j] == 0) continue;
			vector<int> w;
			for (int k = 0; k < n; k++) {
				if (k != j) w.push_back(v[k]);
			}
			sort(w.begin(), w.end());
			LL lo = res*10LL+v[j];
			for (int k = 0; k < w.size(); k++) {
				lo = lo*10LL+w[k];
			}
			if (lo <= b) {
				if (v[j] > d) {
					p = j;
					d = v[j];
				}
			}
		}
		res = res*10LL+d;
		v.erase(v.begin()+p);
		n--;
	}
	while (n > 0);
	cout << res << endl;
	exit(0);
}