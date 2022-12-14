#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
using namespace std;
int32_t main() {
	long long n, m, k;
	int x, y;
	scanf("%lld %lld %lld", &n, &m, &k);
	set<int> row[n], col[m];
	for (int i = 0; i < k; ++i) {
		scanf("%lld %lld", &x, &y);
		row[x - 1].insert(y - 1);
		col[y - 1].insert(x - 1);
	}
	int minr = 0, minc = 0, maxr = n - 1, maxc = m - 1, r = 0, c = 0, dir = 0;
	long long cells = 1;
	while (true) {
		if (dir == 0) {
			set<int>::iterator it = row[r].upper_bound(c);
			int x = maxc + 1;
			if (it != row[r].end()) x = min(x, *it);
			if (x == c + 1) break;
			else cells += x - 1 - c;
			minr = r + 1;
			c = x - 1;
		} else if (dir == 1) {
			set<int>::iterator it = col[c].upper_bound(r);
			int x = maxr + 1;
			if (it != col[c].end()) x = min(x, *it);
			if (x == r + 1) break;
			else cells += x - 1 - r;
			maxc = c - 1;
			r = x - 1;
		} else if (dir == 2) {
			set<int>::iterator it = row[r].upper_bound(c);
			int x = minc - 1;
			if (it != row[r].begin()) x = max(x, *(--it));
			if (x == c - 1) break;
			else cells += c - 1 - x;
			maxr = r - 1;
			c = x + 1;
		} else {
			set<int>::iterator it = col[c].upper_bound(r);
			int x = minr - 1;
			if (it != col[c].begin()) x = max(x, *(--it));
			if (x == r - 1) break;
			else cells += r - 1 - x;
			minc = c + 1;
			r = x + 1;
		}
		dir = (dir + 1) % 4;
	}
	if (cells == n * m - k) printf("Yes");
	else {
		int minr = 0, minc = 0, maxr = n - 1, maxc = m - 1, r = 0, c = 0, dir = 1;
		long long cells = 1;
		while (true) {
			if (dir == 0) {
				set<int>::iterator it = row[r].upper_bound(c);
				int x = maxc + 1;
				if (it != row[r].end()) x = min(x, *it);
				if (x == c + 1) break;
				else cells += x - 1 - c;
				minr = r + 1;
				c = x - 1;
			} else if (dir == 1) {
				set<int>::iterator it = col[c].upper_bound(r);
				int x = maxr + 1;
				if (it != col[c].end()) x = min(x, *it);
				if (x == r + 1) break;
				else cells += x - 1 - r;
				maxc = c - 1;
				r = x - 1;
			} else if (dir == 2) {
				set<int>::iterator it = row[r].upper_bound(c);
				int x = minc - 1;
				if (it != row[r].begin()) x = max(x, *(--it));
				if (x == c - 1) break;
				else cells += c - 1 - x;
				maxr = r - 1;
				c = x + 1;
			} else {
				set<int>::iterator it = col[c].upper_bound(r);
				int x = minr - 1;
				if (it != col[c].begin()) x = max(x, *(--it));
				if (x == r - 1) break;
				else cells += r - 1 - x;
				minc = c + 1;
				r = x + 1;
			}
			dir = (dir + 1) % 4;
		}
		if (cells == n * m - k) printf("Yes");
		else printf("No");
	}
	return 0;
}