#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

#define maxn 100500

using namespace std;

struct list {
	long long x;
	int id;
} sm[maxn];

int n, k;
long long b;
int used[maxn];
long long a[maxn];
long long sum[maxn];

bool cmp (const list &a, const list &b) {
	return (a.x > b.x || a.x == b.x && a.id < b.id);
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> k >> b;
	for (int i = 0; i < n; ++i) {
		cin >> sm[i].x;
		a[i] = sm[i].x;
		sm[i].id = i + 1;
	}
	sort (sm, sm + n - 1, cmp);
	sum[0] = 0;
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + sm[i - 1].x;
		used[sm[i - 1].id] = i;
	}
	for (int i = 1; i < n; ++i) {
		long long first_k = sum[k - 1];
		if (used[i] < k) {
			first_k = sum[k];
		} else {
			first_k += a[i - 1];
		}
		if (first_k > b) {
			cout << i << endl;
			return 0;
		}
	}
	cout << n;
	return 0;
}