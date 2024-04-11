#include <cstdio>
#include <algorithm>

#define maxn 100500

struct larec {
	int k, a;
};

bool cmp(const larec &a, const larec &b) {
	return (a.k < b.k);
}

using namespace std;

larec sm[maxn];
int curnum, curk, n;

/*int num(int p1, int sz1, int p2) {
	if (sz1 == 0)
		return 0;
	int ans = sz1;
	while (ans != 1 && p1 != p2) {
		p1++;
		ans = (ans + 3) / 4;
	}
	return ans;
}*/

bool ok(int sz) {
	for (int i = 0; i < n; ++i) {
		if (sz - sm[i].k <= 0 || sz - sm[i].k < 15 && (1 << (2 * (sz - sm[i].k))) < sm[i].a)
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &sm[i].k, &sm[i].a);
	/*sort(sm, sm + n, cmp);
	curnum = -1, curk = 0;
	for (int i = 0; i < n; ++i) {
		int szlar = num(curnum, curk, sm[i].k);
		curnum = max(szlar, sm[i].a);
		curk = sm[i].k;
	}
	while (curnum != 1) {
		curnum = (curnum + 3) / 4;
		++curk;
	}*/
	int l = -1, r = 1000000100;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (ok(m))
			r = m;
		else
			l = m;
	}
	printf("%d\n", r);
	return 0;
}