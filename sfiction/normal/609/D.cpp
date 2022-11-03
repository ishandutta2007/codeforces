#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, int> PLI;

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10;

int n, K;
ll S;
PLI a[MAXN], b[MAXN];

int m, m1, m2;
PLI c[MAXN], d[MAXN];

int check(int x){
	int l = min(m1, K);
	ll sum = 0;
	for (int i = 0; i < l; ++i)
		sum += c[i].st * a[x].st;
	for (int i = 0; i < K - l; ++i)
		sum += d[i].st * b[x].st;
	if (sum <= S)
		return l;
	for (; K - l < m2 && 0 < l; --l){
		sum -= c[l - 1].st * a[x].st;
		sum += d[K - l].st * b[x].st;
		if (sum <= S)
			return l - 1;
	}
	return -1;
}

int main(){
	scanf("%d%d%d%I64d", &n, &m, &K, &S);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i].st), a[i].nd = i + 1;
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i].st), b[i].nd = i + 1;
	for (int i = 1; i < n; ++i){
		a[i] = min(a[i], a[i - 1]);
		b[i] = min(b[i], b[i - 1]);
	}
	for (int t, i = 0; i < m; ++i){
		scanf("%d", &t);
		scanf("%d", &(t == 1 ? (c[m1].nd = i + 1, c[m1++].st) : (d[m2].nd = i + 1, d[m2++].st)));
	}
	sort(c, c + m1);
	sort(d, d + m2);
	int low = 0, high = n, mid;
	while (low < high){
		mid = high + low >> 1;
		if (~check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n", low == n ? -1 : low + 1);
	if (low < n){
		int l = check(low);
		for (int i = 0; i < l; ++i)
			printf("%d %d\n", c[i].nd, a[low].nd);
		for (int i = 0; i < K - l; ++i)
			printf("%d %d\n", d[i].nd, b[low].nd);
	}
	return 0;
}