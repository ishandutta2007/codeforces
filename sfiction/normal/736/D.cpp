#include <cstdio>
#include <bitset>

using namespace std;

const int MAXN = 2E3, MAXM = 5E5 + 10;

int n, m;
bitset<MAXN> a[MAXN], b[MAXN];
int x[MAXM], y[MAXM];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d", x + i, y + i);
		a[--x[i]].set(--y[i]);
	}

	for (int i = 0; i < n; ++i)
		b[i].set(i);
	int r = 0;
	for (int c = 0; c < n; ++c){
		int i = r;
		for (; i < n && !a[i].test(c); ++i);
		if (i == n)
			break;
		swap(a[r], a[i]), swap(b[r], b[i]);
		for (i = r + 1; i < n; ++i)
			if (a[i].test(r))
				a[i] ^= a[r], b[i] ^= b[r];
		++r;
	}
	for (int i = n - 1; i > 0; --i){
		for (int j = i - 1; j >= 0; --j)
			if (a[j].test(i))
				a[j] ^= a[i], b[j] ^= b[i];
	}
	for (int i = 0; i < m; ++i)
		puts(r == n && !b[y[i]].test(x[i]) ? "YES" : "NO");
	return 0;
}