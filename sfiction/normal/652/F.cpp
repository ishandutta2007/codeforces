#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 3E5 + 10;

int n, m;
ll T;
pair<int, PII> a[MAXN];
int b[MAXN], ans[MAXN];

int main(){
	scanf("%d%d%I64d", &n, &m, &T);
	char dire[5];
	int cnt = 0;
	for (int loc, i = 0; i < n; ++i){
		scanf("%d%s", &a[i].st, dire);
		--a[i].st;
		a[i].nd = PII(i, dire[0] == 'R');
		cnt += a[i].nd.nd;
	}
	if (cnt == 0){
		for (int i = 0; i < n; ++i)
			printf("%d%c", (int)(((a[i].st - T) % m + m) % m + 1), "\n "[i < n - 1]);
		return 0;
	}

	sort(a, a + n);
	int l = 0;
	for (; !a[l].nd.nd; ++l);
	int l0 = (l + T / m * (n - cnt) * 2) % n;

	ll end = a[l].st + T % m;
	for (++l; a[l % n].st + l / n * m < end + T % m; ++l)
		l0 += a[l % n].nd.nd == 0;
	l0 %= n;

	for (int i = 0; i < n; ++i)
		b[i] = ((a[i].st + (a[i].nd.nd ? T : -T)) % m + m) % m;
	sort(b, b + n);

	end %= m;
	int loc = 0;
	for (; end != b[loc]; ++loc);
	for (int i = 0; i < n; ++i)
		ans[a[(l0 + i) % n].nd.st] = b[(loc + i) % n] + 1;
	for (int i = 0; i < n; ++i)
		printf("%d%c", ans[i], "\n "[i < n - 1]);

	return 0;
}