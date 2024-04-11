#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<long long>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<long long>b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<long long>pref2(m);
	pref2[0] = b[0];
	long long z = 0;
	for (int i = 0; i < n; i++) {
		z += a[i];
	}
	for (int i = 1; i < m; i++) {
		pref2[i] = pref2[i - 1] + b[i];
	}
	if (pref2[m - 1] != z) {
		cout << -1;
		return 0;
	}
	long long x = 0;
	int cnt = 0;
	int la = -1;
	int mm = 0;
	int l = 0;
	int r = 0;
	long long www = 0;
	for (int i = 0; i < n; i++) {
		x += a[i];
		l = 0;
		r = m;
		while (r - l > 1) {
			mm = (l + r) / 2;
			if (pref2[mm] - www <= x) {
				l = mm;
			}
			else {
				r = mm;
			}
		}
		if (pref2[l] - www == x) {
			x = 0;
			cnt++;
			la = l;
			www = pref2[l];
		}
		
		
	}
	if (x == 0) {
		cout << cnt;
	}
	
	return 0;
}