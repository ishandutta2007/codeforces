#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct trie {
	int s, e, cnt;
	trie *l, *r;
	trie(int _s, int _e) {
		s = _s, e = _e, cnt = 0;
		l = r = NULL;
	}
	void add(int x) {
		++cnt;
		if (s == e) return;
		if (x > (s + e) / 2) {
			if (r == NULL) r = new trie((s + e) / 2 + 1, e);
			r -> add(x);
		} else {
			if (l == NULL) l = new trie(s, (s + e) / 2);
			l -> add(x);
		}
	}
	int count() {
		if (s == e) return cnt;
		int a = (l == NULL ? 0 : l -> count()), b = (r == NULL ? 0 : r -> count());
		return max(a, b) + min(1, min(a, b));
	}
};
int main() {
	trie* node = new trie(0, (1 << 30) - 1);
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) node -> add(a[i]);
	printf("%d", n - node -> count());
	return 0;
}