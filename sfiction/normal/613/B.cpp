#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10;

int n;
ll A, cf, cm, tot;
PII a[MAXN];
ll s[MAXN];
int out[MAXN];

int main(){
	scanf("%d%I64d%d%d%I64d", &n, &A, &cf, &cm, &tot);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i].st);
		a[i].nd = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i].st;
	int r = 1, ans = -1, ansm, ansr;
	ll score = 0;
	for (int i = 0; i <= n; ++i)
		if (A * (n - i) - (s[n] - s[i]) <= tot){
			ll res = tot - (A * (n - i) - (s[n] - s[i]));
			for (; r <= i && a[r].st * (ll)r <= res + s[r]; ++r);
			ll m = min(A, i == 0 ? A : (res + s[r - 1]) / (r - 1));
			ll ts = (n - i) * cf + m * cm;
			if (ans == -1 || score < ts){
				ans = i;
				ansm = m;
				ansr = r;
				score = ts;
			}
		}
	printf("%I64d\n", score);
	for (int i = 1; i < ansr; ++i)
		out[a[i].nd] = ansm;
	for (int i = ansr; i <= ans; ++i)
		out[a[i].nd] = a[i].st;
	for (int i = ans + 1; i <= n; ++i)
		out[a[i].nd] = A;
	for (int i = 1; i <= n; ++i)
		printf("%d%c", out[i], "\n "[i < n]);

	return 0;
}