#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int MAXN = 1E5 + 10;

int n, m, m1, m2;
PIII a[MAXN], b[MAXN], d[MAXN << 1];
int c[MAXN * 3];

int sum[MAXN * 3];

inline int lowbit(int x){
	return x & (x ^ x - 1);
}

void update(int i, int c){
	for (; i <= m; i += lowbit(i))
		sum[i] += c;
}

int query(int i){
	int res = 0;
	for (; i > 0; i -= lowbit(i))
		res += sum[i];
	return res;
}

void standard(PIII a[], int &n){
	sort(a, a + n);
	int n1 = -1;
	for (int i = 0; i < n; ++i){
		if (n1 < 0 || a[i].st != a[n1].st || a[n1].nd.nd < a[i].nd.st)
			a[++n1] = a[i];
		else if (a[n1].nd.nd < a[i].nd.nd)
			a[n1].nd.nd = a[i].nd.nd;
	}
	n = ++n1;
}

int main(){
	scanf("%d", &n);
	m1 = m2 = 0;
	for (int x1, y1, x2, y2, i = 0; i < n; ++i){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2)
			a[m1++] = PIII(x1, PII(min(y1, y2), max(y1, y2)));
		else
			b[m2++] = PIII(y1, PII(min(x1, x2), max(x1, x2)));
	}
	standard(a, m1);
	standard(b, m2);

//	printf("%d %d\n", m1, m2);

	ll ans = 0;
	for (int i = 0; i < m1; ++i)
		c[m++] = a[i].st, ans += a[i].nd.nd - a[i].nd.st + 1;//, printf("%d %d %d\n", a[i].st, a[i].nd.st, a[i].nd.nd);
	for (int i = 0; i < m2; ++i)
		c[m++] = b[i].nd.st, c[m++] = b[i].nd.nd, ans += b[i].nd.nd - b[i].nd.st + 1;//, printf("%d %d %d\n", b[i].st, b[i].nd.st, b[i].nd.nd);
	sort(c, c + m);
	m = unique(c, c + m) - c;

	for (int i = 0; i < m1; ++i)
		d[i << 1] = PIII(a[i].nd.st, PII(-1, a[i].st)), d[i << 1 | 1] = PIII(a[i].nd.nd, PII(1, a[i].st));
	int m11 = m1 << 1;
	sort(d, d + m11);

	for (int j = 0, i = 0; i < m2; ++i){
		for (; j < m11 && (d[j].st < b[i].st || d[j].st == b[i].st && d[j].nd.st < 0); ++j)
			update(upper_bound(c, c + m, d[j].nd.nd) - c, -d[j].nd.st);//, printf("%d\n", upper_bound(c, c + m, d[j].nd.nd) - c);
//		printf("j = %d\n", j);
		int l = upper_bound(c, c + m, b[i].nd.st) - c, r = upper_bound(c, c + m, b[i].nd.nd) - c;
//		printf("%d %d\n", l, r);
		ans -= query(r) - query(l - 1);
	}
	printf("%I64d\n", ans);

	return 0;
}