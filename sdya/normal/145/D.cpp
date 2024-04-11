#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

bool isLucky(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int n, a[maxN];
long long d[maxN];
map < int, int > p;
vector < int > g[maxN];
int cg;

long long getWays(long long n) {
	return (n * (n + 1)) / 2LL;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	d[1] = 1;
	for (int i = 2; i < maxN; ++i) {
		d[i] = d[i - 1] + ((long long)(i) * (long long)(i + 1)) / 2LL;
	}
	scanf("%d", &n);
	vector < int > positions;
	positions.push_back(0);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (isLucky(a[i])) {
			positions.push_back(i);
			if (p.count(a[i]) == 0) {
				p[a[i]] = cg++;
			}
			g[p[a[i]]].push_back(i);
		}
	}
	positions.push_back(n + 1);

	/*long long triv = 0;
	for (int l1 = 1; l1 <= n; ++l1) {
		for (int r1 = l1; r1 <= n; ++r1) {
			for (int l2 = r1 + 1; l2 <= n; ++l2) {
				for (int r2 = l2; r2 <= n; ++r2) {
					set < int > s;
					for (int i = l1; i <= r1; ++i) {
						if (isLucky(a[i])) {
							s.insert(a[i]);
						}
					}

					bool ok = true;
					for (int i = l2; i <= r2; ++i) {
						if (isLucky(a[i]) && s.count(a[i]) != 0) {
							ok = false;
							break;
						}
					}
					if (ok) {
						triv ++;
					}
				}
			}
		}
	}
	cout << triv << endl;*/

	long long res = 0;
	vector < int > t;
	for (int i = 1; i < positions.size(); ++i) {
		for (int end = positions[i] - 1; end > positions[i - 1]; --end) {
			long long A = end - positions[i - 1];
			long long B = getWays(n - end);
			res += A * B;
		}
	}

	for (int i = 1; i + 1 < positions.size(); ++i) {
		set < int > bounds;
		bounds.insert(positions[i]);
		bounds.insert(n + 1);
		if (positions[i] == n) {
			continue;
		}

		long long s = n - positions[i];
		long long q = positions[i + 1] - positions[i] - 1;
		long long total = 0;
		set < int > used;
		for (int j = i; j > 0; --j) {
			int id = p[a[positions[j]]];
			int index = upper_bound(g[id].begin(), g[id].end(), positions[i]) - g[id].begin();
			if (!used.count(id)) {
				for (int k = index; k < g[id].size(); ++k) {
					int pos = g[id][k];
					bounds.insert(pos);

					set < int > ::iterator it = bounds.find(pos);
					set < int > ::iterator lt = it;
					--lt;
					set < int > ::iterator rt = it;
					++rt;

					int u = *lt;
					int v = *rt;
					if (u == positions[i]) {
						s = pos - u - 1;
						total += getWays(v - pos - 1);
					} else {
						total -= getWays(v - u - 1);
						total += getWays(pos - u - 1);
						total += getWays(v - pos - 1);
					}
				}
				used.insert(id);
			}

			long long A = positions[j] - positions[j - 1];

			res += A * (min(s, q) + 1LL) * total;
			if (s > 0) {
				res += A * (d[s] - (s == q ? 0LL : d[s - q - 1]));
			}
		}
	}

	cout << res << endl;

	return 0;
}