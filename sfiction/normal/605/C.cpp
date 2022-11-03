#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E6 + 10;

PII a[MAXN];
int que[MAXN];

ll cross(ll x1, ll y1, ll x2, ll y2){
	return x1 * y2 - x2 * y1;
}

int main(){
	int n, p, q;	
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].st, &a[i].nd);
	sort(a, a + n);
	n = unique(a, a + n) - a;

	int r = 0;
	que[0] = 0;
	for (int i = 1; i < n; ++i){
		for (; r >= 0 && cross(a[i].st - a[que[r]].st, a[i].nd - a[que[r]].nd, 1, 0) < 0
				|| r >= 1 && cross(a[i].st - a[que[r]].st, a[i].nd - a[que[r]].nd, a[que[r - 1]].st - a[que[r]].st, a[que[r - 1]].nd - a[que[r]].nd) >= 0; --r);
		que[++r] = i;
	}

	double ans;
	if (cross(a[que[0]].st, a[que[0]].nd, p, q) >= 0)
		ans = q / (double)a[que[0]].nd;
	else if (cross(a[que[r]].st, a[que[r]].nd, p, q) <= 0)
		ans = p / (double)a[que[r]].st;
	else{
		int i = 1;
		for (; cross(a[que[i]].st, a[que[i]].nd, p, q) < 0; ++i);
		ll x1 = a[que[i - 1]].st, y1 = a[que[i - 1]].nd;
		ll x2 = a[que[i]].st, y2 = a[que[i]].nd;
		double lemma = (x2 * q - y2 * p) / (double)(p * (y1 - y2) - q * (x1 - x2));
		ans = p / (x2 + lemma * (x1 - x2));
	}
	printf("%.8lf\n", ans);
	return 0;
}