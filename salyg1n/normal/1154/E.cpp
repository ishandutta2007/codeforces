#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <unordered_set>
#include <cmath>
#include <queue>
 
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n, 0);
	set<pair<int, int>> s;
	set<int> m = {n + 1, -1};
	int cnt = n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert({ a[i], i });
		m.insert(i);
	}
	int who = 1;
	while (cnt) {
		int mx = s.rbegin()->second;
		b[mx] = who;
		s.erase(*s.rbegin());
		m.erase(mx);
		cnt--;
		int cntr = 0, now = mx+1;
		while (cntr < k && now < n) {
			if (b[now] == 0) {
				s.erase({ a[now], now });
				m.erase(now);
				b[now] = who;
				cntr++;
				now++;
				cnt--; 
			}
			else {
				now = *m.lower_bound(now);
			}
		}
		int cntl = 0;
		now = mx - 1;
		while (cntl < k && now >= 0) {
			if (b[now] == 0) {
				s.erase({ a[now], now });
				m.erase(now);
				b[now] = who;
				cntl++;
				now--;
				cnt--;
			}
			else {
				now = *(--m.lower_bound(now));
			}
		}
		if (who == 1)
			who = 2;
		else
			who = 1;
	}
	for (auto i : b)
		cout << i;
	return 0;
}