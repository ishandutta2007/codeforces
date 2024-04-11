#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

#define sz(x) int((x).size())
#define repi(i, a) for(typeof(a.begin()) i = a.begin(), _##i = a.end(); i != _##i; ++i)

const int MAXN = 100100;
int ar[MAXN];

set<int> sols;

void count(int left, int right) {
	if (left + 1 == right) {
		sols.insert(ar[left]);
	} else {
		int mid = (left + right) / 2;
		set<int> a, b;
		int k = 0;
		for(int x = mid - 1; x >= left; x--) {
			k |= ar[x];
			a.insert(k);
		}
		k = 0;
		for(int x = mid; x < right; x++) {
			k |= ar[x];
			b.insert(k);
		}
		repi(x, a) {
			repi(y, b) {
				sols.insert(*x | *y);
			}
		}
		count(left, mid);
		count(mid, right);
	}
}
int N;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	count(0, N);
	int ans = sz(sols);
	printf("%d\n", ans);
	return 0;
}